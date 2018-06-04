#include "ir.h"

struct IRList *first;

static char *newVar(int type)
{
	char prefix;
	static int varCount = 1, tempCount = 1, labelCount = 1;
	int no;
	switch((int)type)
	{
		case TYPE_VAR: prefix = 'v'; no = varCount++; break;
		case TYPE_TEMP: prefix = 't'; no = tempCount++; break;
		case TYPE_LABEL: prefix = 'L'; no = labelCount++; break;
	}
	char *buf = malloc(10);
	sprintf(buf, "%c%d%c", prefix, no, '\0');
	return buf;
}

static void translateError(char *msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(EXIT_FAILURE);
}

/*#######################################################################################*/
static struct Operand *newOperand(enum OPKIND kind, enum TYPE type)
{
	struct Operand *op = (struct Operand *)malloc(sizeof(struct Operand));
	memset(op, 0, sizeof(op));
	op->kind = kind;
	op->type = type;
	return op;
}

static struct Operand *constantOperand(int value)
{
	struct Operand *op = newOperand(CONSTANT, NORMAL);
	op->constant = value;
	return op;
}

static struct Operand *varOperand(enum OPKIND kind, enum TYPE type, char *text)
{
	struct Operand *op = newOperand(kind, type);
	op->text = text;
	return op;
}

static struct Operand *copy(struct Operand *operand)
{
	struct Operand *op = newOperand(operand->kind, operand->type);
	if(operand->kind == CONSTANT)
		op->constant = operand->constant;
	else
		op->text = operand->text;
	return op;
}

/*###################################################################################*/
static struct IR* newIR(enum IRKIND kind)
{
	struct IR* ir = (struct IR*)malloc(sizeof(struct IR));
	ir->kind = kind;
	return ir;
}

static struct IR* singleOpIR(enum IRKIND kind, struct Operand *operand)
{
	struct IR *ir = newIR(kind);
	ir->oneop.op = operand;
	return ir;
}

static struct IR* decIR(struct Operand *var, int size)
{
	struct IR *ir = newIR(DEC_IR);
	ir->dec.var = var;
	ir->dec.size = size;
	return ir;
}

static struct IR* binOpIR(enum IRKIND kind, struct Operand *dest, struct Operand *src)
{
	struct IR *ir = newIR(kind);
	ir->binop.dest = dest;
	ir->binop.src = src;
	return ir;	
}

static struct IR* triOpIR(enum IRKIND kind, struct Operand *dest, struct Operand *o1, struct Operand *o2)
{
	struct IR *ir = newIR(kind);
	ir->triop.dest = dest;
	ir->triop.op1 = o1;
	ir->triop.op2 = o2;
	return ir;
}

static struct IR* condJumpIR(struct Operand *op1, struct Operand *op2, 
							struct Operand *dst, char *relop)
{
	struct IR* ir = newIR(COND_JUMP_IR); 
	ir->condjump.op1 = op1;
	ir->condjump.op2 = op2;
	ir->condjump.dest = dst;
	ir->condjump.relop = relop;
	return ir;
}

/*####################################################################################*/
/*Create a empty Intermediate code linked list. Initially, It contains an unused 
  head node. Next and prev fields all point to itsellf
*/
static struct IRList *createIRNode()
{
	struct IRList *irList = (struct IRList *)malloc(sizeof(struct IRList));
	irList->ir =  NULL;
	irList->next = irList;
	irList->prev = irList;
	return irList;
}

static void insertIR(struct IRList *head, struct IR *ir)
{
	struct IRList *node = createIRNode();
	node->ir = ir;
	node->prev = first->prev;
	node->next = first;
	first->prev->next = node;
	first->prev = node;
}


/*########################################################################################*/
static void writeOp(struct Operand *op, FILE *out)
{
	if(op->kind == CONSTANT)
		fprintf(out, "#%d", op->constant);
	else
	{
		if(op->type == ADDRESS)
			fprintf(out, "&");
		else if(op->type == STAR)
			fprintf(out, "*");
		fprintf(out, "%s", op->text);
	}
}

static void writeIR(struct IR* ir, FILE *out)
{
	switch(ir->kind)
	{
		case LABEL_IR: case FUNCTION_IR: case PARAM_IR:case RETURN_IR:
		case GOTO_IR: case ARG_IR: case READ_IR: case WRITE_IR:
			switch(ir->kind)
			{
				case LABEL_IR: fprintf(out, "LABEL ");break;
				case FUNCTION_IR: fprintf(out, "FUNCTION "); break;
				case PARAM_IR: fprintf(out, "PARAM "); break;
				case RETURN_IR: fprintf(out, "RETURN "); break;
				case GOTO_IR: fprintf(out, "GOTO "); break;
				case ARG_IR: fprintf(out, "ARG "); break;
				case READ_IR: fprintf(out, "READ "); break;
				case WRITE_IR: fprintf(out, "WRITE "); break;
			}
			writeOp(ir->oneop.op, out);
			if(ir->kind == LABEL_IR || ir->kind == FUNCTION_IR)
				fprintf(out, " :");
			break;
		case DEC_IR: 
			fprintf(out, "DEC "); 
			writeOp(ir->dec.var, out); 
			fprintf(out, " %d", ir->dec.size); break;
		case ASSIGN_IR: case CALL_IR:
			writeOp(ir->binop.dest, out); 
			fprintf(out, " := "); 
			if(ir->kind == CALL_IR)
				fprintf(out, "CALL ");
			writeOp(ir->binop.src, out);break;
		case MUL_IR: case ADD_IR: case SUB_IR: case DIVIDE_IR: 
			writeOp(ir->triop.dest, out); fprintf(out, " := "); 
			writeOp(ir->triop.op1, out); 
			switch(ir->kind)
			{
				case MUL_IR: fprintf(out, " * "); break;
				case ADD_IR: fprintf(out, " + "); break;
				case SUB_IR: fprintf(out, " - "); break;
				case DIVIDE_IR: fprintf(out, " / "); break;
			}
			writeOp(ir->triop.op2, out); break;
		case COND_JUMP_IR:
			fprintf(out, "IF ");
			writeOp(ir->condjump.op1, out);
			fprintf(out, " %s ", ir->condjump.relop);
			writeOp(ir->condjump.op2, out);
			fprintf(out, " GOTO ");
			writeOp(ir->condjump.dest, out);
		default: break;
	}
	fprintf(out, "\n");
}

static void printIRList(struct IRList *head, FILE *out)
{
	if(head == first)
		return;
	writeIR(head->ir, out);
	printIRList(head->next, out);
}

/*##################################################################################*/
static int calculate_width(struct Type *t)
{
	if(t->kind == BASIC)
	{
		t->width = 4;
		return 4;
	}
	t->width = t->array.size * calculate_width(t->array.elem);
	return t->width;
}

/*###############################################################################*/

static void translate_ExtDefList(struct Node *);
void translate(struct Node *root, FILE *out)
{
	first = createIRNode();
	struct Node *ExtDefList = root->children[0];
	translate_ExtDefList(ExtDefList);
	printIRList(first->next, out);
}

struct Param
{
	char *var;
	struct Param *next;
};

static struct Param *currentParams;

static void insertParam(char *text)
{
	struct Param *param = (struct Param *)malloc(sizeof(struct Param));
	param->var = text;
	param->next = NULL;
	if(currentParams == NULL)
		currentParams = param;
	else
	{
		param->next = currentParams;
		currentParams = param;
	}
}

static int isInCurrentParams(char *text)
{
	struct Param *p = currentParams;
	while(p)
	{
		if(strcmp(p->var, text) == 0)
			return 1;
		p = p->next;
	}
	return 0;
}


static void translate_CompSt(struct Node *);
static void translate_ExtDefList(struct Node *root)
{
	struct Node *ExtDef = NULL;
	struct Node *funDec = NULL;
	struct FieldList *fun, *params = NULL;
	while(root->nr_child != 0)
	{
		ExtDef = root->children[0];
		if(strcmp(ExtDef->children[1]->data->name, "FunDec") == 0)
		{
			funDec = ExtDef->children[1];
			fun = lookup(funDec->children[0]->data->strval);
			params = fun->type->function.params;
			struct Operand *opfunc = varOperand(FUNC, NORMAL, fun->name);
			insertIR(first, singleOpIR(FUNCTION_IR, opfunc));
			currentParams = NULL;
			while(params)
			{
				params->var = newVar(TYPE_VAR);
				params->type->width = calculate_width(params->type);
				insertParam(params->var);
				struct Operand *opparam = varOperand(VARIABLE, NORMAL, params->var);
				insertIR(first, singleOpIR(PARAM_IR, opparam));
				params = params->tail;
			}
			translate_CompSt(ExtDef->children[2]);
		}
		root = root->children[1];
	}	
}

static void translate_Stmt(struct Node *);
static void translate_DefList(struct Node *);
static void translate_CompSt(struct Node *root)
{
	translate_DefList(root->children[1]);
	struct Node *StmtList = root->children[2];
	while(StmtList->nr_child == 2)
	{
		struct Node *Stmt = StmtList->children[0];
		translate_Stmt(Stmt);
		StmtList = StmtList->children[1];
	}
}

static void translate_Cond(struct Node *, struct Operand *, struct Operand *);
static void translate_IF(struct Node *root)
{
	struct Operand *label1 = varOperand(VARIABLE, NORMAL, newVar(TYPE_LABEL)),
				   *label2 = varOperand(VARIABLE, NORMAL, newVar(TYPE_LABEL)),
				   *label3 = NULL;
	translate_Cond(root->children[2], label1, label2);
	insertIR(first, singleOpIR(LABEL_IR, label1));
	translate_Stmt(root->children[4]);
	int hasElse = ((root->nr_child == 7) ? 1: 0);
	if(hasElse)
	{
		label3 = varOperand(VARIABLE, NORMAL, newVar(TYPE_LABEL));
		insertIR(first, singleOpIR(GOTO_IR, label3));
	}
	insertIR(first, singleOpIR(LABEL_IR, label2));
	if(hasElse)
	{
		translate_Stmt(root->children[6]);
		insertIR(first, singleOpIR(LABEL_IR, label3));
	}
}

static void translate_WHILE(struct Node *root)
{
	struct Operand *label1 = varOperand(VARIABLE, NORMAL, newVar(TYPE_LABEL)),
				   *label2 = varOperand(VARIABLE, NORMAL, newVar(TYPE_LABEL)),
				   *label3 = varOperand(VARIABLE, NORMAL, newVar(TYPE_LABEL));
	insertIR(first, singleOpIR(LABEL_IR, label1));
	translate_Cond(root->children[2], label2, label3);
	insertIR(first, singleOpIR(LABEL_IR, label2));
	translate_Stmt(root->children[4]);
	insertIR(first, singleOpIR(GOTO_IR, label1));
	insertIR(first, singleOpIR(LABEL_IR, label3));
}

static void translate_Exp(struct Node *, struct Operand *);
static void translate_Stmt(struct Node *root)
{
	if(strcmp(root->children[0]->data->name, "CompSt") == 0)
		translate_CompSt(root->children[0]);
	else if(strcmp(root->children[0]->data->name, "Exp") == 0)
		translate_Exp(root->children[0], NULL);
	else if(strcmp(root->children[0]->data->name, "RETURN") == 0)
	{
		struct Operand *op = varOperand(VARIABLE, NORMAL, newVar(TYPE_TEMP));
		translate_Exp(root->children[1], op);
		insertIR(first, singleOpIR(RETURN_IR, op));
	}
	else if(strcmp(root->children[0]->data->name, "WHILE") == 0)
		translate_WHILE(root);
	else
		translate_IF(root);
}

static void translate_Cond(struct Node *root, struct Operand *trueLabel, struct Operand *falseLabel)
{
	if(root->nr_child == 3 && strcmp(root->children[1]->data->name, "RELOP") == 0)
	{
		struct Operand *t1 = varOperand(VARIABLE, NORMAL, newVar(TYPE_TEMP)),
					   *t2 = varOperand(VARIABLE, NORMAL, newVar(TYPE_TEMP));
		translate_Exp(root->children[0], t1);
		translate_Exp(root->children[2], t2);
		char *relop = root->children[1]->data->strval;
		insertIR(first, condJumpIR(t1, t2, trueLabel, relop));
		insertIR(first, singleOpIR(GOTO_IR, falseLabel));	
	}
	else if(root->nr_child == 2 && strcmp(root->children[0]->data->name, "NOT") == 0)
	{
		translate_Cond(root->children[1], falseLabel, trueLabel);
	}
	else if(root->nr_child == 3 && strcmp(root->children[1]->data->name, "AND") == 0)
	{
		struct Operand *label = varOperand(VARIABLE, NORMAL, newVar(TYPE_LABEL));
		translate_Cond(root->children[0], label, falseLabel);
		insertIR(first, singleOpIR(LABEL_IR, label));
		translate_Cond(root->children[2], trueLabel, falseLabel);
	}
	else if(root->nr_child == 3 && strcmp(root->children[1]->data->name, "OR") == 0)
	{
		struct Operand *label = varOperand(VARIABLE, NORMAL, newVar(TYPE_LABEL));
		translate_Cond(root->children[0], trueLabel, label);
		insertIR(first, singleOpIR(LABEL_IR, label));
		translate_Cond(root->children[2], trueLabel, falseLabel);
	}
	else
	{
		struct Operand *t = varOperand(VARIABLE, NORMAL, newVar(TYPE_TEMP)),
					   *zero = constantOperand(0);
		translate_Exp(root, t);
		insertIR(first, condJumpIR(t, zero, trueLabel, "!="));
		insertIR(first, singleOpIR(GOTO_IR, falseLabel));
	}
}

static char *findVarName(struct Node *VarDec)
{
	while(VarDec->nr_child != 1)
		VarDec = VarDec->children[0];
	return VarDec->children[0]->data->strval;
}

static void translate_DefList(struct Node *root)
{
	while(root->nr_child == 2)
	{
		struct Node *DecList = root->children[0]->children[1];
		while(1)
		{
			struct Node *Dec = DecList->children[0];
			struct Node *VarDec = Dec->children[0];
			char *name = findVarName(VarDec);
			struct FieldList *var = lookup(name);
			if(var->type->kind == STRUCTURE)
				translateError("Can't translate: Code contains variables of structure type.");
			var->var = newVar(TYPE_VAR);
			if(var->type->kind == ARRAY)
			{	
				var->type->width = calculate_width(var->type);
				struct Operand *decop = varOperand(VARIABLE, NORMAL, var->var);
				insertIR(first, decIR(decop, var->type->width));
			}
			if(Dec->nr_child == 3)
			{
				struct Operand *op = newOperand(VARIABLE, NORMAL);
				op->text = var->var;
				translate_Exp(Dec->children[2], op);
			}
			if(DecList->nr_child == 1)
				break;
			DecList = DecList->children[2];
		}
		root = root->children[1];
	}
}

/* L -> ID LB Exp RB | L  LB Exp RB */
static struct Type *translate_Array(struct Node *root, struct Operand *place)
{
	static char *var[10];
	static int level = 0;
	struct Type *ret = NULL;
	if(strcmp(root->children[0]->children[0]->data->name, "ID") == 0)
	{
		struct Node *ID = root->children[0]->children[0];
		struct FieldList *field = lookup(ID->data->strval);
		var[level++] = field->var;
		place->text = newVar(TYPE_VAR);
		struct Operand *op = NULL;
		if(strcmp(root->children[2]->children[0]->data->name, "INT") == 0)
		{
			int value = root->children[2]->children[0]->data->intval * field->type->array.elem->width;
			op = constantOperand(value);
			insertIR(first, binOpIR(ASSIGN_IR, copy(place), op));
		}
		else
		{
			op = varOperand(VARIABLE, NORMAL, newVar(TYPE_TEMP));
			translate_Exp(root->children[2], op);
			struct Operand *width = constantOperand(field->type->array.elem->width);
			insertIR(first, triOpIR(MUL_IR, copy(place), op, width));
		}
		ret = field->type->array.elem;
	}
	else
	{
		struct Operand *base = newOperand(VARIABLE, NORMAL);
		struct Type *type = translate_Array(root->children[0], base);
		place->text = newVar(TYPE_TEMP);

		struct Operand *op = varOperand(VARIABLE, NORMAL, newVar(TYPE_TEMP)),
					   *index = varOperand(VARIABLE, NORMAL, newVar(TYPE_TEMP)),
					   *width = constantOperand(type->array.elem->width);
		translate_Exp(root->children[2], index);
		insertIR(first, triOpIR(MUL_IR, op, index, width));
		insertIR(first, triOpIR(ADD_IR, copy(place), base, op));
		ret = type->array.elem;
	}
	if(ret->kind == INT)
	{
		struct Operand *dest = varOperand(VARIABLE, NORMAL, newVar(TYPE_TEMP)),
					   *addr = varOperand(VARIABLE, ADDRESS, var[--level]);
		if(isInCurrentParams(addr->text))
			addr->type = NORMAL;
		insertIR(first, triOpIR(ADD_IR, dest, addr, copy(place)));
		place->type = STAR;
		place->text = dest->text;
	}
	return ret;
}

/*root->Exp1 ASSIGNOP Exp2
  Exp1 -> ID | Exp LB Exp RB
*/
static void translate_Assignment(struct Node *root, struct Operand *place)
{
	struct Operand* dest = NULL;
	if(root->children[0]->nr_child == 1)
	{
		struct Node *ID = root->children[0]->children[0];
		struct FieldList *field = lookup(ID->data->strval);
		dest = varOperand(VARIABLE, NORMAL, field->var);
	}
	else
	{
		dest = varOperand(VARIABLE, NORMAL, newVar(TYPE_TEMP));
		translate_Array(root->children[0], dest);
	}
	struct Operand *src = varOperand(VARIABLE, NORMAL, newVar(TYPE_TEMP));
	translate_Exp(root->children[2], src);
	insertIR(first, binOpIR(ASSIGN_IR, dest, src));
	if(place)
		insertIR(first, binOpIR(ASSIGN_IR, place, dest));
}

static int isConditionExp(struct Node *root)
{
	char *cond[] = {"AND", "OR", "RELOP"};
	if(root->nr_child == 2 && strcmp(root->children[0]->data->name, "NOT") == 0)
		return 1;
	if(root->nr_child == 3)
		for(int i = 0; i < 3; i++)
			if(strcmp(cond[i], root->children[1]->data->name) == 0)
				return 1;
	return 0;
}

static void translate_Arithmetic(struct Node *root, struct Operand *place)
{
	struct Operand *t1 = varOperand(VARIABLE, NORMAL, newVar(TYPE_TEMP));
	struct Operand *t2 = varOperand(VARIABLE, NORMAL, newVar(TYPE_TEMP));
	translate_Exp(root->children[0], t1);
	translate_Exp(root->children[2], t2);
	enum IRKIND type;
	char *name = root->children[1]->data->name;
	if(strcmp(name, "PLUS") == 0)
		type = ADD_IR;
	else if(strcmp(name, "MINUS") == 0)
		type = SUB_IR;
	else if(strcmp(name, "STAR") == 0)
		type = MUL_IR;
	else
		type = DIVIDE_IR;
	insertIR(first, triOpIR(type, place, t1, t2));
}

static struct Arg *newArg(struct Operand *var)
{
	struct Arg *arg = (struct Arg *)malloc(sizeof(struct Arg));
	arg->arg = var;
	arg->next = NULL;
	return arg;
}

static struct Arg* insertArg(struct Arg *list, struct Operand *operand)
{
	if(list == NULL)
		list = newArg(operand);
	else
	{
		struct Arg *new = newArg(operand);
		new->next = list;
		list = new;
	}
	return list;
}

static struct Arg* translate_Args(struct Node *root, struct Arg *list)
{
	struct Operand *t = varOperand(VARIABLE, NORMAL, newVar(TYPE_TEMP));
	translate_Exp(root->children[0], t);
	list = insertArg(list, t);
	if(root->nr_child == 3)
		list = translate_Args(root->children[2], list);
	return list;
}

static void translate_funCall(struct Node *root, struct Operand *place)
{
	char *funcName = root->children[0]->data->strval;
	if(strcmp(funcName, "read") == 0)
		insertIR(first, singleOpIR(READ_IR, place));
	else if(strcmp(funcName, "write") == 0)
	{
		struct Operand *t = varOperand(VARIABLE, NORMAL, newVar(TYPE_TEMP));
		translate_Exp(root->children[2]->children[0], t);
		insertIR(first, singleOpIR(WRITE_IR, t));
	}
	else
	{
		 if(root->nr_child == 4)
		 {
			struct Arg *args = NULL;
			args = translate_Args(root->children[2], args);
			while(args)
			{
				insertIR(first, singleOpIR(ARG_IR, args->arg));
				args = args->next;
			}
		}
		struct Operand *func = varOperand(FUNC, NORMAL, funcName);
		if(!place)
			place = varOperand(VARIABLE, NORMAL, newVar(TYPE_TEMP));
		insertIR(first, binOpIR(CALL_IR, place, func));
	}
}

static void translate_Exp(struct Node *root, struct Operand *place)
{
	if(root->nr_child == 1)
	{
		if(place && strcmp(root->children[0]->data->name, "INT") == 0)
		{
			struct Operand *src = constantOperand(root->children[0]->data->intval);
			insertIR(first, binOpIR(ASSIGN_IR, place, src));
		}
		else if(place)
		{
			struct FieldList *field = lookup(root->children[0]->data->strval);
			struct Operand *src = varOperand(VARIABLE, NORMAL, field->var);
			if(field->type->kind == ARRAY && isInCurrentParams(field->var) == 0)
				src->type = ADDRESS;
			insertIR(first, binOpIR(ASSIGN_IR, place, src));
		}
	}
	else if(isConditionExp(root))
	{
		struct Operand *label1 = varOperand(VARIABLE, NORMAL, newVar(TYPE_LABEL)), 
					   *label2 = varOperand(VARIABLE, NORMAL, newVar(TYPE_LABEL)),
					   *zero = constantOperand(0),
					   *one = constantOperand(1);
		insertIR(first, binOpIR(ASSIGN_IR, place, zero));
		translate_Cond(root, label1, label2);
		insertIR(first, singleOpIR(LABEL_IR, label1));
		insertIR(first, binOpIR(ASSIGN_IR, place, one));
		insertIR(first, singleOpIR(LABEL_IR, label2));
	}
	else if(strcmp(root->children[1]->data->name, "LP") == 0)
		translate_funCall(root, place);
	else if(root->nr_child == 2)
	{
		struct Operand *zero = constantOperand(0);
		struct Operand *t = varOperand(VARIABLE, NORMAL, newVar(TYPE_TEMP));
		translate_Exp(root->children[1], t);
		insertIR(first, triOpIR(SUB_IR, place, zero, t));	
	}
	else if(root->nr_child == 3)
	{
		if(strcmp(root->children[1]->data->name, "ASSIGNOP") == 0)
			translate_Assignment(root, place);
		else if(strcmp(root->children[1]->data->name, "Exp") == 0)
			translate_Exp(root->children[1], place);
		else
			translate_Arithmetic(root, place);
	}
	else	
	{
		if(strcmp(root->children[0]->data->name, "Exp") == 0)
			translate_Array(root, place);	
	}
}
