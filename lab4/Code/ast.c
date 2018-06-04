#include "ast.h"
#include <stdarg.h>

/************************************************************************************* 
create a new tree node, set all it's attributes, initially, it has zero children
If this node expresses ID TYPE INT FLOAT, we need to get more attribute values use
extern variables yytext, yyleng and yylineno, function return a pointer to new node
*************************************************************************************/
struct Node *createNode(char *name, enum NODE_TYPE t)
{
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	if(node == NULL)
	{
		fprintf(stderr, "malloc struct Node failed.\n");
		exit(EXIT_FAILURE);		
	}
	node->nr_child = 0;
	node->children = NULL;
	node->data = (struct NodeData *)malloc(sizeof(struct NodeData));
	if(node->data == NULL)
	{
		fprintf(stderr, "malloc struct NodeData failed.\n");
		exit(EXIT_FAILURE);
	}
	node->data->name = name;
	node->data->type = t;
	node->data->line = yylineno;
	if(strcmp(name, "ID") == 0 || strcmp(name, "TYPE") == 0 || strcmp(name, "RELOP") == 0)
	{
		node->data->strval = (char *)malloc(yyleng);
		strcpy(node->data->strval, yytext);
	}
	else if(strcmp(name, "INT") == 0)
		node->data->intval = atoi(yytext);
	else if(strcmp(name, "FLOAT") == 0)
		node->data->floatval = atof(yytext);
	return node;
}

/******************************************************************************
 Add all members in array child to parent children. Only when parent represent a 
 grammer unit and didn't produce empty string we need to do this.
*******************************************************************************/
struct Node *addchildren(char *name, int n, ...)
{
	struct Node *parent = createNode(name, SYNTACTIC);
	parent->nr_child = n;
	parent->children = (struct Node **)malloc(sizeof(struct Node *) * n);
	if(parent->children == NULL)
	{
		fprintf(stderr, "malloc parent's children failed.\n");
		exit(EXIT_FAILURE);
	}
	/*parent's lineno is the minimum in all children's lineno*/
	va_list ap;
	va_start(ap, n);
	for(int i = 0; i < n; i++)
	{
		struct Node *child = va_arg(ap, struct Node *);
		parent->children[i] = child;
		if(child->data->line < parent->data->line)
			parent->data->line = child->data->line;
	}
	return parent;
}


void preorder(struct Node *node, int level)
{
	/* If current node is non-terminal and has no child, then it produce empty string */
	if(node->data->type == SYNTACTIC && node->nr_child == 0)
		return;
	for(int i = 0; i <level; i++)
		printf("  ");
	printf("%s", node->data->name);
	if(node->data->type == SYNTACTIC)
		printf(" (%d)\n", node->data->line);
	else if(strcmp(node->data->name, "ID") == 0 || strcmp(node->data->name, "TYPE") == 0)
		printf(": %s\n", node->data->strval);
	else if(strcmp(node->data->name, "INT") == 0)
		printf(": %d\n", node->data->intval);
	else if(strcmp(node->data->name, "FLOAT") == 0)
		printf(": %f\n", node->data->floatval);
	else 
		printf("\n");
	for(int i = 0; i < node->nr_child; i++)
		preorder(node->children[i], level+1);
}
