%{
int yylex();
%}

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void yyerror(const char *message);

/** If you need global variable, declare them here **/
struct variable{
    char id[64] ;
    int value ;
};
struct variable PlaceVariable[2] ;
int nowIndex = 0 ;
int hasNotFind =  0 ;
%}

%union{
	char sval[64];
	int ival;
}

%token IF INT PRINT
%token<ival> NUMBER
%token<sval> ID STRING
%type<ival> id_val
%type<sval> stdout

/** above: definition section **/
%% 

program		: def_stmt def_stmt cond_exp
			;
def_stmt	: INT ID '=' NUMBER ';' {  
                strcpy( PlaceVariable[ nowIndex ].id, $2 );
                PlaceVariable[ nowIndex ].value = $4 ;
                nowIndex ++ ;
            }
			;
cond_exp	: IF '(' id_val '>' id_val ')' stdout {
                if( hasNotFind == 1 ) yyerror("error");
                else{
                    if( $3 > $5 ) { printf("%s\n", $7 ); }
                    printf("Compiled successfully\n");
                }
            }
			;
id_val		: ID { 
                int Find =  0 ;
                for( int i = 0 ; i < 2 ; i ++ ) {
                    if( strcmp( PlaceVariable[i].id, $1 ) == 0 ) { 
                        $$ = PlaceVariable[i].value ;
                        Find = 1 ;
                    }
                } 
                // 我現在要處理相關的問題
                if( Find == 0 ) hasNotFind = 1 ;
            }
			;
stdout		: '{' PRINT '(' STRING ')' ';' '}' { strcpy( $$, $4 ); } 
			;

/** above: rule section * */
%%

void yyerror (const char *message)
{
	/** This function is called when there is a syntax error **/
	/** 輸入的文法錯誤時會 call 這個 function **/
    printf("Invalid input\n");
}

int main()
{
	/** You can write any code in main function **/
	yyparse();

	return 0;
}

/** above: subroutine section **/