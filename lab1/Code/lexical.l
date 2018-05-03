%option yylineno

%{
	#include "syntax.tab.h"
	#include "ast.h"
	extern int error;
%}

letter_ [_a-zA-Z]
digit [0-9]
delim [\n\t\r ]

ws {delim}+
ID {letter_}({letter_}|{digit})*
INT ([1-9]{digit}*)|0 
FLOAT {INT}\.{digit}+|{INT}(\.{digit}+)?[eE][+-]?{digit}+
TYPE int|float

%%

{ws} {/* no action and no return */}
{INT}    { yylval.node = createNode("INT", LEXICAL); return INT;}
{FLOAT}  { yylval.node = createNode("FLOAT", LEXICAL); return FLOAT;}
{TYPE}   { yylval.node = createNode("TYPE", LEXICAL); return TYPE; }
"if" 	 { yylval.node = createNode("IF", LEXICAL); return IF; }
"else"	 { yylval.node = createNode("ELSE", LEXICAL); return ELSE; }
"while"	 { yylval.node = createNode("WHILE", LEXICAL); return WHILE; }
"struct" { yylval.node = createNode("STRUCT", LEXICAL); return STRUCT; }
"return" { yylval.node = createNode("RETURN", LEXICAL); return RETURN; }
"="      { yylval.node = createNode("ASSIGNOP", LEXICAL); return ASSIGNOP;}
"<" 	 { yylval.node = createNode("RELOP", LEXICAL); return RELOP;}
">" 	 { yylval.node = createNode("RELOP", LEXICAL); return RELOP;}
"<="	 { yylval.node = createNode("RELOP", LEXICAL); return RELOP;}
">=" 	 { yylval.node = createNode("RELOP", LEXICAL); return RELOP;}
"=="	 { yylval.node = createNode("RELOP", LEXICAL); return RELOP;}
"!=" 	 { yylval.node = createNode("RELOP", LEXICAL); return RELOP;}
"&&"	 { yylval.node = createNode("AND", LEXICAL); return AND; }
"||"	 { yylval.node = createNode("OR", LEXICAL); return OR; }
"!"		 { yylval.node = createNode("NOT", LEXICAL); return NOT; }
"."		 { yylval.node = createNode("DOT", LEXICAL); return DOT; }
"(" 	 { yylval.node = createNode("LP", LEXICAL); return LP; }
")"		 { yylval.node = createNode("RP", LEXICAL); return RP; }
"["		 { yylval.node = createNode("LB", LEXICAL); return LB; }
"]"		 { yylval.node = createNode("RB", LEXICAL); return RB; }
"{"		 { yylval.node = createNode("LC", LEXICAL); return LC; }
"}"		 { yylval.node = createNode("RC", LEXICAL); return RC; }
"+"		 { yylval.node = createNode("PLUS", LEXICAL); return PLUS; }
"-"		 { yylval.node = createNode("MINUS", LEXICAL); return MINUS;}
"/"		 { yylval.node = createNode("DIV", LEXICAL); return DIV;}
"*"		 { yylval.node = createNode("STAR", LEXICAL); return STAR; }
";"		 { yylval.node = createNode("SEMI", LEXICAL); return SEMI; }
","		 { yylval.node = createNode("COMMA", LEXICAL); return COMMA; }
{ID} 	 { yylval.node = createNode("ID", LEXICAL); return ID;}

. { error = 1; printf("Error type A at Line %d: Mysterious characters \'%s'\'\n", yylineno, yytext);}

%%


