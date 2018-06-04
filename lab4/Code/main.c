#include <stdio.h>
#include "ast.h"
#include "semantic.h"
#include "ir.h"

extern int yyparse();
extern void yyrestart(FILE *);

int error = 0;

extern struct Node *root;

int main(int argc, char **argv)
{
	if(argc <= 1)	
		return 1;
	FILE *f = fopen(argv[1],"r");
	if(!f)
	{
		perror(argv[1]);
		return 1;
	}
	yyrestart(f);
	yyparse();
	if(error)
	{
		printf("Detected lexical error/syntax error.\n");
		exit(EXIT_FAILURE);
	}
	Program(root);
	FILE *irFile = stdout;
	if(argc == 3)
		irFile = fopen(argv[2], "wt");
	translate(root, irFile);
	fclose(irFile);
	return 0;
}
