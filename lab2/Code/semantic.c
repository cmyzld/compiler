#include "semantic.h"

/********************************************************************************************/
//SYMBOL TABLE (HASH)

#define MAX_FUNCTION 1000

static int inStruct = 0;
static char* functions[MAX_FUNCTION];
int fcnt = 0;

void initTable()
{
	for(int i = 0; i < TSIZE; i++)
		table[i] = NULL;
}

unsigned int hash(char *name)
{
	unsigned int i, val = 0;
	for(; *name; ++name)
	{
		val = (val << 2) + *name;
		if((i = val) & (~0x3FFF)) 
			val = (val ^ (i >> 12)) & 0x3FFF;
	}
	return val;
}

int insert(struct FieldList *fl)
{
	unsigned int h = hash(fl->name);
	for(int i = 0; i < TSIZE; i++)
	{
		int p = (h + i) % TSIZE;
		if(table[p] == NULL)
		{
			table[p] = fl;
			return 1;
		}
	}
	return 0;
}

struct FieldList* lookup(char *name)
{
	unsigned int h = hash(name);
	for(int i = 0; i < TSIZE; i++)
	{
		int p = (h + i) % TSIZE;
		/*Find the key or find our key entry*/
		if(table[p] == NULL || strcmp(table[p]->name, name) == 0)
			return table[p];
	}
	/*No empty slot and didn't find our key */
	return NULL;
}

void insertList(struct FieldList* fields)
{
	struct FieldList* p = fields;
	while(p != NULL)
	{
		int error15 = 0;
		if(inStruct != 0)
		{
			struct FieldList *q = fields;
			while(q != p)
			{
				if(strcmp(q->name, p->name) == 0)
				{
					printf("Error type 15 at Line %d: Redefined field \"%s\".\n", p->line, p->name);
					error15 = 1;
					break;
				}
				q = q->tail;
			}		
		}
		if(error15 == 0)
		{
			if(lookup(p->name) != NULL)
				printf("Error type 3 at Line %d: Redefined variable \"%s\".\n", p->line, p->name);
			else
				insert(p);
		}
		p = p->tail;
	}	
}
/********************************************************************************************/


void Program(struct Node *r)
{
	ExtDefList(r->children[0]);
	for(int i = 0; i < fcnt; i++)
	{
		struct FieldList* f = lookup(functions[i]);	
		if(f->type->function.state == DECLARED)
			printf("Error type 18 at Line %d: Undefined function \"%s\".\n",f->line,  functions[i]);
	}
}

void ExtDefList(struct Node *r)
{
	struct Node *ExtDefList = r;
	while(ExtDefList->nr_child == 2)
	{
		struct Node *ExtDef = ExtDefList->children[0];
		struct Type* type = Specifier(ExtDef->children[0]);

		if(strcmp(ExtDef->children[1]->data->name, "FunDec") == 0)
		{
			int define = strcmp(ExtDef->children[2]->data->name, "CompSt") == 0 ? 1 : 0;
			struct Type* ftype = FunDec(ExtDef->children[1], type, define);
			if(define == 1)
				CompSt(ExtDef->children[2], ftype);
		}
		else if(strcmp(ExtDef->children[1]->data->name, "ExtDecList") == 0)
		{
			struct Node* ExtDecList = ExtDef->children[1];
			while(1)
			{
				struct Node* varDec = ExtDecList->children[0];
				struct FieldList *field = VarDec(varDec, type);
				if(lookup(field->name) != NULL)
					printf("Error type 3 at Line %d: Redefined variable \"%s\".\n", varDec->data->line, field->name);
				else
					insert(field);
				if(ExtDecList->nr_child == 1)
					break;
				ExtDecList = ExtDecList->children[2];
			}
		}
		ExtDefList = ExtDefList->children[1];
	}	
}

struct Type* FunDec(struct Node* r, struct Type* retType, int define)
{
	struct FieldList *field = lookup(r->children[0]->data->strval);
	struct FieldList *params = NULL;
	struct Type* type = (struct Type*)malloc(sizeof(struct Type));
	if(r->nr_child == 4)
	{
		struct Node* VarList = r->children[2];
		while(1)
		{
			struct Node* ParamDec = VarList->children[0];	
			struct Type* type = Specifier(ParamDec->children[0]);
			struct FieldList *param = VarDec(ParamDec->children[1], type);
			FieldAppend(&params, param);
			if(VarList->nr_child == 1)
				break;
			VarList = VarList->children[2];
		}
	}
	if(define)
		insertList(params);
	type->kind = FUNCTION;
	type->function.state = ((define==1)?DEFINED:DECLARED);
	type->function.params = params;
	type->function.retValueType = retType;
	if(field == NULL)
	{
		field = (struct FieldList *)malloc(sizeof(struct FieldList));		
		field->line = r->data->line;
		field->name = r->children[0]->data->strval;
		field->type = type;
		insert(field);
		functions[fcnt++] = field->name;
	}
	else
	{
		if(define == 1 && field->type->function.state == DEFINED)
			printf("Error type 4 at Line %d: Redefined function \"%s\".\n", r->data->line, field->name);
		else
		{
			if(typeCheck(type, field->type) == 0)
			{
				if(type->function.state != field->type->function.state)
					printf("Error type 19 at Line %d: confilt function declaration and definition.\n", r->data->line);
				else
					printf("Error type 19 at Line %d: Inconsistent declaration of function \"%s\".\n", r->data->line, field->name);
			}
			if(define == 1)
				field->type->function.state = DEFINED;
		}
	}
	return type;
}

struct Type* Specifier(struct Node *r)
{
	struct Type *type = (struct Type *)malloc(sizeof(struct Type));
	struct Node* TS = r->children[0];
	if(strcmp(TS->data->name, "TYPE") == 0)
	{
		type->kind = BASIC;
		type->basic = (strcmp(r->children[0]->data->strval, "int") == 0)?INT:FLOAT;
	}
	else
	{ 
		type->kind = STRUCTURE;
		struct Node* StructSpecifier = r->children[0];
		if(StructSpecifier->nr_child == 5)
		{
			struct Node* defList = StructSpecifier->children[3];
			inStruct ++;
			struct FieldList* fields = DefList(defList);
			insertList(fields);
			inStruct --;
			type->structure.fields = fields;
			if(StructSpecifier->children[1]->nr_child != 0)
			{
				struct FieldList *stru = (struct FieldList *)malloc(sizeof(struct FieldList));
				stru->line = StructSpecifier->data->line;
				type->structure.name = stru->name = StructSpecifier->children[1]->children[0]->data->strval;
				stru->type = type;
				if(lookup(stru->name) != NULL)
					printf("Error type 16 at line %d: Duplicated name \"%s\".\n", StructSpecifier->data->line, stru->name);
				else
					insert(stru);
			}
		}
		else
		{
			char *name = StructSpecifier->children[1]->children[0]->data->strval;
			struct FieldList *field = lookup(name);
			if(field == NULL)
			{
				printf("Error type 17 at Line %d: Undefined structure \"%s\".\n", StructSpecifier->data->line, name);
				return NULL;
			}
			else
				type = field->type;
		}
	}
	return type;
}


struct FieldList* DefList(struct Node* r)
{
	struct FieldList* fields = NULL;
	while(r->nr_child == 2)
	{
		struct Node* Def = r->children[0];
		struct Type *type = Specifier(Def->children[0]);
		struct Node* DecList = Def->children[1];
		while(1)
		{
			struct Node* Dec = DecList->children[0];		
			struct Node* varDec = Dec->children[0];
			struct FieldList *field = VarDec(varDec, type);
			if(inStruct != 0 && Dec->nr_child == 3)
				printf("Error type 15 at Line %d: can't assign to field \"%s\" in structure.\n", varDec->data->line, field->name);
			if(inStruct == 0)
			{
				if(Dec->nr_child == 3)
				{
					struct Type *t1 = field->type;
					struct Type *t2 = Exp(Dec->children[2]);
					if(t1 && t2 && typeCheck(t1, t2) == 0)
						printf("Error type 5 at Line %d: Type mismatched for assignment.\n", varDec->data->line);
				}
				if(lookup(field->name) != NULL)
					printf("Error type 3 at Line %d: Redefined variable \"%s\".\n", varDec->data->line, field->name);
				else
					insert(field);
			}
			FieldAppend(&fields, field);
			if(DecList->nr_child == 1)
				break;	
			DecList = DecList->children[2];
		}
		r = r->children[1];
	}
	return fields;
}

struct FieldList* VarDec(struct Node* r, struct Type *t)
{
	struct FieldList *field = (struct FieldList *)malloc(sizeof(struct FieldList));
	field->line = r->data->line;
	if(r->nr_child == 1)
	{
		field->name = r->children[0]->data->strval;
		field->tail = NULL;
		field->type = t;
	}
	else			
	{
		struct Node* varDec = r;
		struct Type *type = NULL;
		while(varDec->nr_child == 4)
		{
			struct Type *newtype = (struct Type*)malloc(sizeof(struct Type));
			newtype->kind = ARRAY;
			newtype->array.size = varDec->children[2]->data->intval;
			if(type == NULL)
			{
				type = newtype;
				type->array.elem = t;
			}
			else
			{
				newtype->array.elem = type;
				type = newtype;
			}
			varDec = varDec->children[0];
			if(varDec->nr_child == 1)
				field->name = varDec->children[0]->data->strval;
		}
		field->type = type;
	}
	return field;
}

void CompSt(struct Node* r, struct Type *function)
{
	DefList(r->children[1]);
	struct Node* StmtList = r->children[2];
	while(StmtList->nr_child == 2)
	{
		struct Node* stmt = StmtList->children[0];
		Stmt(stmt, function);
		StmtList = StmtList->children[1];
	}
}

void Stmt(struct Node* stmt, struct Type *function)
{
	if(stmt->nr_child == 1)	//CompSt
		CompSt(stmt->children[0], function);
	else if(stmt->nr_child == 2)
		Exp(stmt->children[0]);
	else if(stmt->nr_child == 3)
	{
		struct Type* t = Exp(stmt->children[1]);
		struct Type* ret = function->function.retValueType;
		
		if(t && ret && typeCheck(t, ret) == 0)
			printf("Error type 8 at Line %d: Type mismatched for return.\n", stmt->data->line);
	}
	else if(strcmp(stmt->children[0]->data->name, "IF") == 0)
	{
		Exp(stmt->children[2]);			
		Stmt(stmt->children[4], function);
		if(stmt->nr_child == 7)
			Stmt(stmt->children[6],function);	
	}
	else
	{
		Exp(stmt->children[2]);
		Stmt(stmt->children[4], function);	
	}
}

struct Type* Exp(struct Node* r)
{
	struct Type *type = NULL;
	if(r->nr_child == 1)
		type = basicType(r);
	else if(strcmp(r->children[0]->data->name, "LP") == 0 || strcmp(r->children[0]->data->name, "MINUS") == 0 || 
			strcmp(r->children[0]->data->name, "NOT") == 0)
		type = Exp(r->children[1]);
	else if(strcmp(r->children[1]->data->name,"PLUS") == 0 || strcmp(r->children[1]->data->name, "MINUS") == 0 ||
			strcmp(r->children[1]->data->name, "STAR") == 0 || strcmp(r->children[1]->data->name, "DIV") == 0)
	{
		struct Type* t1 = Exp(r->children[0]);
		struct Type* t2 = Exp(r->children[2]);
		if((typeCheck(t1, t2) == 0 && t1 && t2) || (t1 && t1->kind != BASIC))
			printf("Error type 7 at Line %d: Type mismatched for operands.\n", r->data->line);
		else
			type = t1;
	}
	else if(strcmp(r->children[1]->data->name, "AND") == 0 || strcmp(r->children[1]->data->name, "OR") == 0 ||
			strcmp(r->children[1]->data->name, "RELOP") == 0)
		type = Exp(r->children[0]);
	else if(strcmp(r->children[0]->data->name, "ID") == 0)	/*function call*/
		type = funCall(r);
	else if(strcmp(r->children[1]->data->name, "LB") == 0)
		type = arrayRef(r);
	else if(strcmp(r->children[1]->data->name, "DOT") == 0)
		type = structRef(r);
	else if(strcmp(r->children[1]->data->name, "ASSIGNOP") == 0)
		type = assignOp(r);
	return type;
}

struct Type* basicType(struct Node* r)
{
	struct Type *type = NULL;
	if(strcmp(r->children[0]->data->name, "ID") == 0)
	{
		struct FieldList* field = lookup(r->children[0]->data->strval);
		if(field == NULL)
			printf("Error type 1 at Line %d: Undefined variable \"%s\".\n", r->data->line, r->children[0]->data->strval);
		else
			type = field->type;
	}
	else if(strcmp(r->children[0]->data->name, "INT") == 0)
	{
		type = (struct Type*)malloc(sizeof(struct Type));
		type->kind = BASIC;
		type->basic = INT;
	}
	else
	{
		type = (struct Type*)malloc(sizeof(struct Type));
		type->kind = BASIC;
		type->basic = FLOAT;
	}
	return type;
}

struct Type* funCall(struct Node* r)
{
	struct Type* type = NULL;
	struct FieldList *f = lookup(r->children[0]->data->strval);
	if(f == NULL)
		printf("Error type 2 at Line %d: Undefined function \"%s\".\n", r->data->line, r->children[0]->data->strval);
	else if(f->type->kind != FUNCTION)
		printf("Error type 11 at Line %d: \"%s\" is not a function.\n", r->data->line, r->children[0]->data->strval);
	else
	{
		struct Node* Args = NULL;
		if(r->nr_child == 4)
			Args = r->children[2];
		struct Type* newtype = (struct Type *)malloc(sizeof(struct Type));
		newtype->kind = FUNCTION;
		newtype->function.retValueType = f->type->function.retValueType;
		while(r->nr_child == 4)
		{
			struct Type *t = Exp(Args->children[0]);
			struct FieldList *nf = (struct FieldList*)malloc(sizeof(struct FieldList));
			nf->type = t;
			FieldAppend(&newtype->function.params, nf);
			if(Args->nr_child == 1)
				break;
			Args = Args->children[2];
		}
		if(newtype && f->type && typeCheck(newtype, f->type) == 0)
			printf("Error type 9 at Line %d: Argument mismatched for function \"%s\".\n", r->data->line, f->name);
		type = f->type->function.retValueType;
	}
	return type;
}

struct Type* arrayRef(struct Node* r)
{
	struct Type* type = NULL;
	struct Type* t1 = Exp(r->children[0]);
	if(Exp(r->children[2])->basic != INT)
		printf("Error type 12 at Line %d: Not an integer between '[' and ']'.\n", r->data->line);
	if(t1 != NULL && t1->kind != ARRAY)
		printf("Error type 10 at Line %d: Illegal use of \"[]\".\n", r->data->line);
	else if(t1 != NULL)
		type = t1->array.elem;
	return type;
}

struct Type* structRef(struct Node* r)
{
	struct Type* type = NULL;
	struct Type* t = Exp(r->children[0]);
	if(t && t->kind != STRUCTURE)
		printf("Error type 13 at Line %d: Illegal use of \".\".\n", r->data->line);
	if(t && t->kind == STRUCTURE)
	{
		struct FieldList* fields = t->structure.fields;
		struct FieldList *field = NULL;
		while(fields!=NULL)
		{
			if(strcmp(fields->name, r->children[2]->data->strval) == 0)
			{
				field = fields;
				break;
			}
			fields = fields->tail;
		}
		if(field == NULL)
			printf("Error type 14 at Line %d: Non-existent field \"%s\".\n", r->data->line, r->children[2]->data->strval);
		else
			type = field->type;
	}
	return type;
}

struct Type* assignOp(struct Node* r)
{
	struct Type* type = NULL;
	struct Type* t1 = Exp(r->children[0]);
	struct Type* t2 = Exp(r->children[2]);
	if(typeCheck(t1, t2) == 0 && t1 && t2)
		printf("Error type 5 at Line %d: Type mismatched for assignment.\n", r->data->line);
	struct Node* lexp = r->children[0];
	int err = 0;
	switch(lexp->nr_child)
	{
		case 1:
			if(strcmp(lexp->children[0]->data->name, "ID") != 0)
				err = 1;
			break;
		case 3:
			if(strcmp(lexp->children[1]->data->name, "DOT") != 0)
				err = 1;
			break;
		case 4:
			if(strcmp(lexp->children[1]->data->name, "LB") != 0)
				err = 1;
			break;
		default:err = 1;
	}
	if(err == 1)
		printf("Error type 6 at Line %d: The left-hand side of an assignment must be a variable.\n", r->data->line);
	else
		type = t1;
	return type;
}

int typeCheck(struct Type *t1, struct Type* t2)
{
	if(t1 == NULL || t2 == NULL)
		return 0;
	if(t1->kind != t2->kind)
		return 0;
	if(t1->kind == BASIC)
		return t1->basic == t2->basic;
	else if(t1->kind == ARRAY)
		return typeCheck(t1->array.elem, t2->array.elem);
	else if(t1->kind == STRUCTURE)	/*Name Equivalence*/
		return strcmp(t1->structure.name, t2->structure.name) == 0;
	else
	{
		if(t1->function.retValueType && t2->function.retValueType 
			&& typeCheck(t1->function.retValueType, t2->function.retValueType) == 0)
			return 0;
		struct FieldList* f1 = t1->function.params;
		struct FieldList* f2 = t2->function.params;
		while(f1 && f2)
		{
			if(typeCheck(f1->type, f2->type) == 0)
				return 0;
			f1 = f1->tail;
			f2 = f2->tail;
		}
		if(f1 == NULL && f2 == NULL)
			return 1;
		return 0;
	}
}
