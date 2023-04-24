%{
#include "hw4.tab.h"
%}

number	(-)?[0-9]+
float   (-)?[0-9]+\.[0-9]+
id		[A-Z]

%%
int		{ return INT; }
float   { return FLOAT; }
print   { return PRINT; }
{float}     { yylval.fval = atof(yytext); return FLOATNUMBER; }  
{number}	{ yylval.ival = atoi(yytext); return INTNUMBER; }
{id}		{ strcpy(yylval.sval,yytext); return ID; }
[=+-;]   { return yytext[0]; } //
[\n\t\r ]+	{}
.			{}
%%

int yywrap(void) {
    return 1;
}