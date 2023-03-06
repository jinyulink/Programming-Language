name [A-Z]+, [A-Z][a-z]+-[A-Z][a-z]+
identity [A-Z][0-9]{9,9}
email [0-9]+@[a-z]+((\.[a-z]+)+)?
birthday [0-9]{2,4}\/[0-9]{2,2}\/[0-9]{2,2}
phone \+886[0-9]{9,9}
%option noyywrap /*告訴flex指讀取輸入檔案*/
%%
/***規則區塊***/
{name}	{ECHO;printf('\n);}
{identity} {printf("identity number: ");ECHO;printf('\n);}
{email} {printf("email: ");ECHO;printf('\n);}
{birthday} {printf("birthday: ");ECHO;printf('\n);}
{phone} {printf("phone: ");ECHO;printf('\n);}
%%
int main(int argc, char *argv[]) {
	yylex();
 	return(0);
}
