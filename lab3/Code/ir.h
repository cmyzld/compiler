#ifndef __INTERCODE__H_
#define __INTERCODE__H_

#include "semantic.h"

#define TYPE_VAR 1
#define TYPE_TEMP 2
#define TYPE_LABEL 3
	
enum OPKIND {VARIABLE, CONSTANT, FUNC};
enum TYPE {ADDRESS, STAR, NORMAL};

struct Operand
{
	enum OPKIND kind;
	enum TYPE type;
	union
	{
		char *text;		/*VARIABLE LABEL */	
		int constant;
	};
};

struct Arg
{
	struct Operand *arg;
	struct Arg *next;
};

enum IRKIND {LABEL_IR, FUNCTION_IR, ASSIGN_IR, ADD_IR, SUB_IR, MUL_IR, DIVIDE_IR, 
	GOTO_IR, COND_JUMP_IR, RETURN_IR, DEC_IR, ARG_IR,  CALL_IR, PARAM_IR, READ_IR, WRITE_IR};

struct IR
{
	enum IRKIND kind;
	union
	{
		struct {struct Operand *op; } oneop;
		struct {struct Operand *var; int size; } dec;
		struct {struct Operand *dest, *src;} binop;	
		struct {struct Operand *op1, *op2, *dest; }triop;
		struct {struct Operand *op1, *op2, *dest; char *relop;} condjump;
	};
};

struct IRList
{
	struct IR *ir;
	struct IRList *prev;
	struct IRList *next;
};


void translate(struct Node *root, FILE *out);

static void translate_ExtDefList(struct Node *root);
static void translate_CompSt(struct Node *root);
static void translate_Stmt(struct Node *root);
static void translate_IF(struct Node *root);
static void translate_WHILE(struct Node *root);
static void translate_DefList(struct Node *root);
static void translate_Assignment(struct Node* root, struct Operand *place);
static struct Type*translate_Array(struct Node *root, struct Operand *place);
static void translate_Arithmetic(struct Node* root, struct Operand* place);
static void translate_Exp(struct Node *root, struct Operand *place);
static void translate_Cond(struct Node *root, struct Operand *t, struct Operand *f);
static int calculate_width(struct Type *t);

/*#####Temp variable malloc################################################################*/
static char *newVar(int type);

/*#####Operand ############################################################################*/
static struct Operand *newOperand(enum OPKIND kind, enum TYPE type);
static struct Operand *constantOperand(int value);
static struct Operand *varOperand(enum OPKIND kind, enum TYPE type, char *text);
static struct Operand *copy(struct Operand *operand);

/*#####InterCode ###########################################################################*/
static struct IR* newIR(enum IRKIND kind);
static struct IR* singleOpIR(enum IRKIND kind, struct Operand *operand);
static struct IR* decIR(struct Operand *var, int size);
static struct IR* binOpIR(enum IRKIND kind, struct Operand *dest, struct Operand *src);
static struct IR* triOpIR(enum IRKIND kind, struct Operand *o, 
							struct Operand *o1, struct Operand *o2);
static struct IR* condJumpIR(struct Operand *o1, struct Operand *o2, 
							struct Operand *o3, char *relop);
/*#####LINK LIST FUNCTIONS###################################################################*/
static struct IRList *first;
static struct IRList *createIRNode();
static void insertIR(struct IRList *head, struct IR *ir);

/*#####PRINT FUNCTIONS#######################################################################*/
static void writeOp(struct Operand *op, FILE *out);
static void writeIR(struct IR *ir, FILE *out);
static void printIRList(struct IRList *head, FILE *out);

#endif
