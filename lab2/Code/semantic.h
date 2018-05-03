#ifndef __SEMANTIC_H__
#define __SEMANTIC_H__

#include "ast.h"

#define TSIZE (0x3fff + 1)

struct FieldList;
struct Type
{
	enum {BASIC, ARRAY, STRUCTURE, FUNCTION} kind;

	union{
		enum {INT, FLOAT}basic;

		struct{ 
			struct Type *elem;
			int size;
		} array;

		struct{
			char *name;
			struct FieldList *fields;
		}structure;
		
		struct {
			enum {DECLARED, DEFINED} state;		/* Whether this function was defined, declared ... */
			struct Type *retValueType;					/* Return value type */
			struct FieldList *params; 					/* Function params*/
		}function;
	};
};

/*A FieldList refer to one symbol, has it's name(lexime)*/
struct FieldList
{
	char *name;
	int line;
	struct Type *type;
	struct FieldList* tail;
};

static inline void FieldAppend(struct FieldList **l1, struct FieldList *l2)
{
	if(*l1 == NULL)
		*l1 = l2;
	else
	{
		struct FieldList *p = *l1;
		while(p->tail != NULL)
			p = p->tail;
		p->tail = l2;
	}
}

struct FieldList* table[TSIZE];

void Program(struct Node *r);
void ExtDefList(struct Node *r);
struct Type* Specifier(struct Node* r);
struct FieldList* DefList(struct Node* r);
struct FieldList* VarDec(struct Node* r, struct Type *t);
struct Type* FunDec(struct Node* r, struct Type* retType, int define);
void CompSt(struct Node* r, struct Type *function);
void Stmt(struct Node* r, struct Type *function);
struct Type* Exp(struct Node* r);

struct Type* basicType(struct Node* r);
struct Type* funCall(struct Node* r);
struct Type* arrayRef(struct Node* r);
struct Type* structRef(struct Node* r);
struct Type* assignOp(struct Node* r);


int typeCheck(struct Type* t1, struct Type* t2);

#endif
