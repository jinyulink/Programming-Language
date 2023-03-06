digit	[0-9]+
%option noyywrap
%%
{digit}	{ECHO;printf(" is digit.\n");}
%%
int main(int argc, char *argv[]) {
	yylex();
 	return(0);
}
