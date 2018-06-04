%{
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "lex.yy.c"
#include "ast.h"

extern int yylex();
extern void yyerror(const char *);
extern int error;
#define YYERROR_VERBOSE
%}

%union{
	struct Node * node;
}

%token <node> INT FLOAT TYPE IF ELSE WHILE STRUCT RETURN
%token <node> RELOP LC RC LB RB LP RP COMMA SEMI
%token <node> ID ASSIGNOP AND OR PLUS MINUS STAR DIV NOT DOT

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%right ASSIGNOP
%left OR
%left AND
%left RELOP
%left PLUS MINUS
%left STAR DIV 
%right NOT
%left LB RB LP RP DOT 

%type <node> Program ExtDefList ExtDef ExtDecList Specifier StructSpecifier 
			 OptTag Tag VarDec FunDec VarList ParamDec CompSt StmtList Stmt 
			 DefList Def DecList Dec Exp Args

%%

/*High-Level Definitions*/
Program    : ExtDefList { root = addchildren("Program", 1, $1); } ;

ExtDefList : ExtDef ExtDefList { $$ = addchildren("ExtDefList", 2, $1, $2);}
		   | { $$ = createNode("ExtDefList", SYNTACTIC); };

ExtDef 	   : Specifier ExtDecList SEMI{ $$ = addchildren("ExtDef", 3, $1, $2, $3);}
	       | Specifier SEMI { $$ = addchildren("ExtDef", 2, $1, $2);}
	       | Specifier FunDec CompSt { $$ = addchildren("ExtDef", 3, $1, $2, $3); }
		   | Specifier FunDec SEMI { $$ = addchildren("ExtDef", 3, $1, $2, $3); }
		   | error SEMI {};

ExtDecList : VarDec	{ $$ = addchildren("ExtDecList", 1, $1); }
		   | VarDec COMMA ExtDecList  { $$ = addchildren("ExtDecList", 3, $1, $2, $3);};


/*Specifiers*/
Specifier : TYPE { $$ = addchildren("Specifier", 1, $1); }
		  | StructSpecifier { $$ = addchildren("Specifier", 1, $1);	};

StructSpecifier: STRUCT OptTag LC DefList RC{ $$ = addchildren("StructSpecifier", 5, $1, $2, $3, $4, $5);}
		  |STRUCT Tag { $$ = addchildren("StructSpecifier", 2, $1, $2); };

OptTag    : ID 	{ $$ = addchildren("OptTag", 1, $1);}
		  | { $$ = createNode("OptTag", SYNTACTIC); } ;

Tag 	  : ID { $$ = addchildren("Tag", 1, $1); };    

/*Declarators*/
VarDec 	  : ID	{ $$ = addchildren("VarDec", 1, $1); }
	   	  | VarDec LB INT RB { $$ = addchildren("VarDec", 4, $1, $2, $3, $4); }
	      | error RB {};

FunDec    : ID LP VarList RP { $$ = addchildren("FunDec", 4, $1, $2, $3, $4);}
          | ID LP RP { $$ = addchildren("FunDec", 3, $1, $2, $3); }
		  | error RP {};

VarList   : ParamDec COMMA VarList { $$ = addchildren("VarList", 3, $1, $2, $3);}
	      | ParamDec { $$ = addchildren("VarList", 1, $1); }
	      | error COMMA {};

ParamDec  : Specifier VarDec { $$ = addchildren("ParamDec", 2, $1, $2);};

/*Statements*/
CompSt    : LC DefList StmtList RC  { $$ = addchildren("CompSt", 4, $1, $2, $3, $4);};
StmtList  : Stmt StmtList { $$ = addchildren("StmtList", 2, $1, $2); }
	 	  |{ $$ = createNode("StmtList", SYNTACTIC); };

Stmt	  : Exp SEMI { $$ = addchildren("Stmt", 2, $1, $2);}
		  | CompSt 	{ $$ = addchildren("Stmt", 1, $1);}
		  | RETURN Exp SEMI{ $$ = addchildren("Stmt", 3, $1, $2, $3);}
		  | IF LP Exp RP Stmt %prec LOWER_THAN_ELSE	{
				$$ = addchildren("Stmt", 5, $1, $2, $3, $4, $5);
		  }
		  | IF LP Exp RP Stmt ELSE Stmt{ $$ = addchildren("Stmt", 7, $1, $2, $3, $4, $5, $6, $7);}
		  | WHILE LP Exp RP Stmt { $$ = addchildren("Stmt", 5, $1, $2, $3, $4, $5);}
		  | error SEMI {};

/*Local Definitions*/
DefList   : Def DefList	{ $$ = addchildren("DefList", 2, $1, $2); }
	      |{ $$ = createNode("DefList", SYNTACTIC); };

Def		  : Specifier DecList SEMI 	{ $$ = addchildren("Def", 3, $1, $2, $3); }
   		  | error SEMI {};

DecList   : Dec { $$ = addchildren("DecList", 1, $1); }
	      | Dec COMMA DecList { $$ = addchildren("DecList", 3, $1, $2, $3);}
		  | error COMMA{};

Dec       : VarDec { $$ = addchildren("Dec", 1, $1);}
   		  | VarDec ASSIGNOP Exp	{ $$ = addchildren("Dec", 3, $1, $2, $3);};

/*Expressions*/
Exp 	  : Exp ASSIGNOP Exp { $$ = addchildren("Exp", 3, $1, $2, $3); }
	      | Exp AND Exp { $$ = addchildren("Exp", 3, $1, $2, $3); }
	      | Exp OR Exp { $$ = addchildren("Exp", 3, $1, $2, $3); }
	      | Exp RELOP Exp{ $$ = addchildren("Exp", 3, $1, $2, $3); }
	      | Exp PLUS Exp { $$ = addchildren("Exp", 3, $1, $2, $3); }
		  | Exp MINUS Exp{ $$ = addchildren("Exp", 3, $1, $2, $3); }
		  | Exp STAR Exp { $$ = addchildren("Exp", 3, $1, $2, $3); }
		  | Exp DIV Exp { $$ = addchildren("Exp", 3, $1, $2, $3); }
		  | LP Exp RP { $$ = addchildren("Exp", 3, $1, $2, $3); }
		  | MINUS Exp { $$ = addchildren("Exp", 2, $1, $2); }
		  | NOT Exp{ $$ = addchildren("Exp", 2, $1, $2); }
		  | ID LP Args RP{ $$ = addchildren("Exp", 4, $1, $2, $3, $4); }
		  | ID LP RP{ $$ = addchildren("Exp", 3, $1, $2, $3); }
		  | Exp LB Exp RB{ $$ = addchildren("Exp", 4, $1, $2, $3, $4); }
		  | Exp DOT ID { $$ = addchildren("Exp", 3, $1, $2, $3); }
		  | ID { $$ = addchildren("Exp", 1, $1); }
		  | INT { $$ = addchildren("Exp", 1, $1); }
		  | FLOAT{ $$ = addchildren("Exp", 1, $1); }
		  | error RP {};

Args	  :Exp COMMA Args{ $$ = addchildren("Args", 3, $1, $2, $3); }
		  |Exp { $$ = addchildren("Args", 1, $1); }
		  |error COMMA {};


%%

void yyerror(const char *s)
{
	error = 1;
	fprintf(stderr, "Error type B at Line %d: %s\n", yylineno,s);
}
