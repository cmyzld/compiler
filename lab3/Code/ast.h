#ifndef __TREENODE__
#define __TREENODE__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

extern char *yytext;
extern int yyleng;
extern int yylineno;

enum NODE_TYPE{LEXICAL, SYNTACTIC};

struct NodeData
{
	enum NODE_TYPE type;
	int line;
	char *name;			
	union{				/* attribute value */
		char *strval;	/* name = ID/TYPE */
		int intval;		/* name = INT */
		float floatval; /* name = FLOAT */
	};
};

struct Node
{
	struct NodeData *data;
	int nr_child;
	struct Node **children;
};

struct Node *root;

struct Node *createNode(char *name, enum NODE_TYPE t);
void addchildren(struct Node *parent, struct Node *child[], int n);
void preorder(struct Node *node, int level);

#endif
