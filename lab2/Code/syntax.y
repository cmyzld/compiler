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
Program    : ExtDefList 
		   { 
				root = createNode("Program", SYNTACTIC); 
				struct Node *children[] = {$1}; 
				addchildren(root, children, 1);
		   } 
           ;

ExtDefList : ExtDef ExtDefList 
		   {
				$$ = createNode("ExtDefList", SYNTACTIC);
				struct Node *children[] = {$1, $2};
				addchildren($$, children, 2);	
		   }
		   | 
		   {
				$$ = createNode("ExtDefList", SYNTACTIC);	
		   }
		   ;

ExtDef 	   : Specifier ExtDecList SEMI
		   {
				$$ = createNode("ExtDef", SYNTACTIC);
				struct Node *children[] = {$1, $2, $3};
				addchildren($$, children, 3);
		   }
	       | Specifier SEMI 		   
		   {
				$$ = createNode("ExtDef", SYNTACTIC);
				struct Node *children[] = {$1, $2};
				addchildren($$, children, 2);
		   }
	       | Specifier FunDec CompSt   
		   {
				$$ = createNode("ExtDef", SYNTACTIC);
				struct Node *children[] = {$1, $2, $3};
				addchildren($$, children, 3);
				//printf("Function Define at line %d\n", yylineno);
		   }
		   | Specifier FunDec SEMI
		   {
				//printf("Function Declarators at line %d\n", yylineno);
				$$ = createNode("ExtDef", SYNTACTIC);
				struct Node* children[] = {$1, $2, $3};
				addchildren($$, children, 3);
		   }
		   | error SEMI 
		   {

		   }
		   ;

ExtDecList : VarDec					   
		   {
				$$ = createNode("ExtDecList", SYNTACTIC);
				struct Node *children[] = {$1};
				addchildren($$, children, 1);
		   }
		   | VarDec COMMA ExtDecList   
		   {
				$$ = createNode("ExtDecList", SYNTACTIC);
				struct Node *children[] = {$1, $2, $3};
				addchildren($$, children, 3);
		   }
           ;


/*Specifiers*/
Specifier : TYPE	 					   
		  {
				$$ = createNode("Specifier", SYNTACTIC);
				struct Node *children[] = {$1};
				addchildren($$, children, 1);
		  }
		  | StructSpecifier 			   
		  {
				$$ = createNode("Specifier", SYNTACTIC);
				struct Node *children[] = {$1};
				addchildren($$, children, 1);		
		  }
          ;

StructSpecifier: STRUCT OptTag LC DefList RC
		  { 
				$$ = createNode("StructSpecifier", SYNTACTIC);
				struct Node *children[] = {$1, $2, $3, $4, $5};
				addchildren($$, children, 5);
		  }
		  |STRUCT Tag 				   
		  {
				$$ = createNode("StructSpecifier", SYNTACTIC);
				struct Node *children[] = {$1, $2};
				addchildren($$, children, 2);
		  }
          ;

OptTag    : ID 							   
		  {
				$$ = createNode("OptTag", SYNTACTIC);
				struct Node *children[] = {$1};
				addchildren($$, children, 1);
		  }
		  | 							   
		  {
				$$ = createNode("OptTag", SYNTACTIC);
		  } 
          ;

Tag 	  : ID 								   
		  { 
				$$ = createNode("Tag", SYNTACTIC);
				struct Node *children[] = {$1};
				addchildren($$, children, 1);
		  }
		  ;    

/*Declarators*/
VarDec 	  : ID	 				     
		  {
				$$ = createNode("VarDec", SYNTACTIC);
				struct Node *children[] = {$1};
				addchildren($$, children, 1);
		  }
	   	  | VarDec LB INT RB
		  {
				$$ = createNode("VarDec", SYNTACTIC);
				struct Node *children[] = {$1, $2, $3, $4};
				addchildren($$, children, 4);
		  }
	      | error RB
		  {

		  }
          ;

FunDec    : ID LP VarList RP 		 
		  { 
				$$ = createNode("FunDec", SYNTACTIC);
				struct Node *children[] = {$1, $2, $3, $4};
				addchildren($$, children, 4);
		  }
          | ID LP RP 				 
		  {
				$$ = createNode("FunDec", SYNTACTIC);
				struct Node *children[] = {$1, $2, $3};
				addchildren($$, children, 3);
		  }
		  | error RP 
		  {

		  }
		  ;

VarList   : ParamDec COMMA VarList 
		  { 
				$$ = createNode("VarList", SYNTACTIC);
				struct Node* children[] = {$1, $2, $3};
				addchildren($$, children, 3);
		  }
	      | ParamDec 				
		  {
				$$ = createNode("VarList", SYNTACTIC);
				struct Node* children[] = {$1};
				addchildren($$, children, 1);
		  }
	      | error COMMA 
		  {

		  }
		  ;

ParamDec  : Specifier VarDec 
		  {
				$$ = createNode("ParamDec", SYNTACTIC);
				struct Node *children[] = {$1, $2};
				addchildren($$, children, 2);
		  }
	      ;

/*Statements*/
CompSt    : LC DefList StmtList RC  
		  { 
				$$ = createNode("CompSt", SYNTACTIC);
				struct Node* children[] = {$1, $2, $3, $4};
				addchildren($$, children, 4);
		  }
		  ;
StmtList  : Stmt StmtList 		 
		  {
				$$ = createNode("StmtList", SYNTACTIC);
				struct Node *children[] = {$1, $2};
				addchildren($$, children, 2);
		  }
	 	  | 						 
		  {
				$$ = createNode("StmtList", SYNTACTIC);
		  }
		  ;

Stmt	  : Exp SEMI 					 
		  { 
				$$ = createNode("Stmt", SYNTACTIC);
				struct Node* children[] = {$1, $2};
				addchildren($$, children, 2);
		  }
		  | CompSt 					
		  {
				$$ = createNode("Stmt", SYNTACTIC);
				struct Node* children[] = {$1};
				addchildren($$, children, 1);
		  }
		  | RETURN Exp SEMI
		  {
				$$ = createNode("Stmt", SYNTACTIC);
				struct Node* children[] = {$1, $2, $3};
				addchildren($$, children, 3);
		  }
		  | IF LP Exp RP Stmt %prec LOWER_THAN_ELSE		 
		  {
				$$ = createNode("Stmt", SYNTACTIC);
				struct Node* children[] = {$1, $2, $3, $4, $5};
				addchildren($$, children, 5);
		  }
		  | IF LP Exp RP Stmt ELSE Stmt
		  { 
				$$ = createNode("Stmt", SYNTACTIC);
				struct Node* children[] = {$1, $2, $3, $4, $5, $6, $7};
				addchildren($$, children, 7);
		  }
		  | WHILE LP Exp RP Stmt 		 
		  {
				$$ = createNode("Stmt", SYNTACTIC);
				struct Node* children[] = {$1, $2, $3, $4, $5};
				addchildren($$, children, 5);
		  }
		  | error SEMI 
		  {

		  }
		  ;

/*Local Definitions*/
DefList   : Def DefList			 
		  {
				$$ = createNode("DefList", SYNTACTIC);
				struct Node* children[] = {$1, $2};
				addchildren($$, children, 2);
		  }
	      | 						 
		  {
				$$ = createNode("DefList", SYNTACTIC);
	      };

Def		  : Specifier DecList SEMI 	 
		  { 
				$$ = createNode("Def", SYNTACTIC);
				struct Node* children[] = {$1, $2, $3};
				addchildren($$, children, 3);
		  }
   		  | error SEMI 
		  {

		  }
		  ;

DecList   : Dec 					 
		  {
				$$ = createNode("DecList", SYNTACTIC);
				struct Node* children[] = {$1};
				addchildren($$, children, 1);
		  }
	      | Dec COMMA DecList 		 
		  {
				$$ = createNode("DecList", SYNTACTIC);
				struct Node* children[] = {$1, $2, $3};
				addchildren($$, children, 3);
		  }
		  | error COMMA
		  {

		  }
		  ;

Dec       : VarDec						 
		  {
				$$ = createNode("Dec", SYNTACTIC);
				struct Node* children[] = {$1};
				addchildren($$, children, 1);
		  }
   		  | VarDec ASSIGNOP Exp		 
		  {
				$$ = createNode("Dec", SYNTACTIC);
				struct Node* children[] = {$1, $2, $3};
				addchildren($$, children, 3);
		  }
		  ;

/*Expressions*/
Exp 	  : Exp ASSIGNOP Exp	
		  {
				$$ = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {$1, $2, $3};
				addchildren($$, children, 3);
	  	  }
	      | Exp AND Exp		
	   	  {
				$$ = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {$1, $2, $3};
				addchildren($$, children, 3);
 	      }
	      | Exp OR Exp		
	   	  {
				$$ = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {$1, $2, $3};
				addchildren($$, children, 3);
		  }
	      | Exp RELOP Exp	    
	  	  { 
				$$ = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {$1, $2, $3};
				addchildren($$, children, 3);
	 	  }
		  | Exp PLUS Exp 		
		  {
				$$ = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {$1, $2, $3};
				addchildren($$, children, 3);
 		  }
		  | Exp MINUS Exp 	
	 	  {
				$$ = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {$1, $2, $3};
				addchildren($$, children, 3);
		  }
		  | Exp STAR Exp 		
	 	  {
				$$ = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {$1, $2, $3};
				addchildren($$, children, 3);
		  }
		  | Exp DIV Exp 		
		  {
				$$ = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {$1, $2, $3};
				addchildren($$, children, 3);
	      }
		  | LP Exp RP 		
		  {
				$$ = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {$1, $2, $3};
				addchildren($$, children, 3);
		  }
		  | MINUS Exp 		
		  {
				$$ = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {$1, $2};
				addchildren($$, children, 2);
		  }
		  | NOT Exp			
		  {
				$$ = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {$1, $2};
				addchildren($$, children, 2);
		  }
		  | ID LP Args RP		
 	 	  {
				$$ = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {$1, $2, $3, $4};
				addchildren($$, children, 4);
		  }
		  | ID LP RP			
		  {
				$$ = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {$1, $2, $3};
				addchildren($$, children, 3);
		  }
		  | Exp LB Exp RB		
	 	  {
				$$ = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {$1, $2, $3, $4};	
				addchildren($$, children, 4);
	 	  }
		  | Exp DOT ID 		
		  {
				$$ = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {$1, $2, $3};
				addchildren($$, children, 3);
		  }
		  | ID 				
		  {

				$$ = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {$1};
				addchildren($$, children, 1);
		  }
		  | INT 				
		  {
				$$ = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {$1};
				addchildren($$, children, 1);
		  }
		  | FLOAT 			
		  {
				$$ = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {$1};
				addchildren($$, children, 1);
		  }
		  | error RP 
		  {

		  }
		  ;

Args	  :Exp COMMA Args 	
		  {
				$$ = createNode("Args", SYNTACTIC);
				struct Node* children[] = {$1, $2, $3};
				addchildren($$, children, 3);
	      }
		  |Exp 				
		  {
				$$ = createNode("Args", SYNTACTIC);
				struct Node* children[] = {$1};
				addchildren($$, children, 1);
		  }
		  |error COMMA 
		  {

		  }
		  ;


%%

void yyerror(const char *s)
{
	error = 1;
	fprintf(stderr, "Error type B at Line %d: %s\n", yylineno,s);
}
