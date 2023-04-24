%{
int yylex();
%}

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void yyerror( const char *message );

/** If you need global variable, declare them here **/

struct Variable{
	char 	type[6]		 ;
    char	id[1] 		 ;
    int		intValue 	 ;
	float	floatValue	 ;
};

struct Variable PlaceVariable[64];
int currentIndex = 0 ;
int line = 1 ;

%}

%union{
    int   ival;
	float fval;
	char  sval[64];
	struct rval {
		char   type[6];
		float  f;
		int    i;
	} rval;
}

%token INT FLOAT PRINT
%token<ival> INTNUMBER
%token<fval> FLOATNUMBER
%token<sval> ID 
%type<rval> id_val

// 定義優先順序3
%left '='
%left '+' '-'


%%


program		: stmtlist
			;

stmtlist	: stmt stmtlist
			| stmt

stmt		: stdout
			| assign_stmt
			| def_stmt
			;
def_stmt	: INT ID ';' {
				int Find = 0;
                int j;
				for(int i = 0; i < currentIndex; i++) {
					if(strcmp(PlaceVariable[i].id, $2) == 0) {
                        j=i;
                        Find = 1;
						break;
					}
                }
				if(Find == 1){
                    char error[64]={};
                    strcat(error, "Variable ");
                    strcat(error, $2);
                    strcat(error, " redeclaration. Error in line ");
					yyerror(error);
					return 1;
				}
				else{
					strcpy(PlaceVariable[currentIndex].type, "INT  ");
					strcpy(PlaceVariable[currentIndex].id, $2);
					PlaceVariable[currentIndex].intValue = 0;
					currentIndex++;
				}
				line++;
            }
			| FLOAT ID ';' {
				int Find = 0;
                int j;
                for(int i = 0; i < 64; i++) {
					if(strcmp(PlaceVariable[i].id, $2) == 0) {
                        j=i;
						Find = 1;
                        break;
                    }
                }
                if(Find == 1){
                    char error[64]={};
                    strcat(error, "Variable ");
                    strcat(error, $2);
                    strcat(error, " redeclaration. Error in line ");
					yyerror(error);
                	return 1;
				}
                else{
					strcpy(PlaceVariable[currentIndex].type, "FLOAT");
					strcpy(PlaceVariable[currentIndex].id, $2);
					PlaceVariable[currentIndex].floatValue = 0.0;
					currentIndex++;
				}
				line++;
			}
			;
assign_stmt	: ID '=' id_val ';' {
				// 先判斷ID有沒有被宣告
				char typeID[6];
				int  indexID;
				int Find = 0;
                int j;
				for(int i = 0; i < currentIndex; i++) {
					if(strcmp(PlaceVariable[i].id, $1) == 0) {
                        j=i;
                        Find = 1;
						indexID = i;
						strcpy(typeID, PlaceVariable[i].type);
						break;
					}
                }
				// printf("%s.,%s.\n", $<rval.type>3, typeID);
				if(Find == 0){
                    char error[64]={};
                    strcat(error, "Variable ");
                    strcat(error, $1);
                    strcat(error, " undefined. Error in line ");
					yyerror(error);
					return 1;
				}			
				
				// 判斷等號兩邊型態的正確性
				else if(strcmp($<rval.type>3, typeID) != 0){
					yyerror("Type error. Error in line ");
					return 1;
				}
				// 將計算結果放回去(先省略)

				line++;
			}
			;
id_val		: id_val '+' id_val {
				// printf("%s.,%s.\n", $<rval.type>1, $<rval.type>3);
				if(!strcmp($<rval.type>1, "FLOAT") && !strcmp($<rval.type>3, "FLOAT")){
					strcpy($<rval.type>$, "FLOAT");
					$<rval.f>$ = $<rval.f>1 + $<rval.f>3;
				}else if(!strcmp($<rval.type>1, "FLOAT") && !strcmp($<rval.type>3, "INT  ")){
					yyerror("Type error. Error in line ");
					return 1;
				}else if(!strcmp($<rval.type>1, "INT  ") && !strcmp($<rval.type>3, "FLOAT")){
					yyerror("Type error. Error in line ");
					return 1;
				}else{
					strcpy($<rval.type>$, "INT  ");
					$<rval.i>$ = $<rval.i>1 + $<rval.i>3;
				}
			}
			| id_val '-' id_val {
				if($<rval.type>1 == "FLOAT" && $<rval.type>3 == "FLOAT"){
					strcpy($<rval.type>$, "FLOAT");
					$<rval.f>$ = $<rval.f>1 - $<rval.f>3;
				}else if($<rval.type>1 == "FLOAT" && $<rval.type>3 == "INT  "){
					yyerror("Type Error. Error in line ");
					return 1;
				}else if($<rval.type>1 == "INT  " && $<rval.type>3 == "FLOAT"){
					yyerror("Type Error. Error in line ");
					return 1;
				}else{
					strcpy($<rval.type>$, "INT  ");
					$<rval.i>$ = $<rval.i>1 - $<rval.i>3;
				}
			}
			| INTNUMBER {
				strcpy($<rval.type>$, "INT  ");
				$<rval.i>$ = $1;				
			}
			| FLOATNUMBER {
				strcpy($<rval.type>$, "FLOAT");
				$<rval.f>$ = $1;
			}
			| ID {
				int Find = 0;
                int j;
				for(int i = 0; i < currentIndex; i++) {
					if(strcmp(PlaceVariable[i].id, $1) == 0) {
                        j=i;
                        Find = 1;
						strcpy($<rval.type>$, PlaceVariable[i].type);
						if(strcmp(PlaceVariable[i].type, "FLOAT") == 0) {
							$<rval.f>$ = PlaceVariable[i].floatValue;
						}
						else if(strcmp(PlaceVariable[i].type, "INT  ") == 0){
							$<rval.i>$ = PlaceVariable[i].intValue;
						}
						break;
					}
                }
				if(Find == 0){
                    char error[64]={};
                    strcat(error, "Variable ");
                    strcat(error, $1);
                    strcat(error, " undefined. Error in line ");
					yyerror(error);
					return 1;
				}
			}
			;
stdout		: PRINT ID ';'
			;
%%

void yyerror (const char *message)
{
	/** This function is called when there is a syntax error **/
	/** 輸入的文法錯誤時會 call 這個 function **/
    printf("%s%d.", message, line);
}

int main()
{
	/** You can write any code in main function **/
	yyparse();

	return 0;
}