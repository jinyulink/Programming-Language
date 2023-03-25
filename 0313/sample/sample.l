%{
#include "hw3.tab.h"
#include "string.h"

/** RE 請換成 regular expression **/
%}
%option noyywrap

number	(-)?[0-9]+
id		([a-z]|[A-Z]|_)([A-Z]|[a-z]|_|[0-9])*
string	\"(.)+\" 

%%

int		{ return INT; }
if		{ return IF; }
printf    	{ return PRINT; }
[=;()<>{}]   { return yytext[0]; }
{number}	{ yylval.ival = atoi(yytext); return NUMBER; }
{id}		{ strcpy(yylval.sval,yytext); return ID; }
{string}	{ strcpy(yylval.sval,yytext); return STRING; }

[\n\t\r ]	{}
.			{}

%%
/** yylval是一个表示不同语义值的集合，其中的ival cval dval sval 分别用来保存 整数 字符 浮点数 字符串 单词的语义值。 **/
/** yytext holds the text matched by the current token. So yytext[0] holds the first character of the text matched by the current token. **/
/**  yylval
This is a variable defined in *.y file 
When token is returned  to yacc , yacc can use it to do something
yylval.ival = atoi(yytext);
sprintf(yylval.sval, "%s", yytext);
strncpy(yylval.sval, &yytext[5], strlen(yytext)-3);
**/