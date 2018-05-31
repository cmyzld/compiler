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
	union{
		char *text;	
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

struct IR{
	enum IRKIND kind;
	union{
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


extern void translate(struct Node *root, FILE *out);

#endif
