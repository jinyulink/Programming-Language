%{
#include <iostream>
using namespace std;
int counter=0;
%}
name [A-Z]+,\ [A-Z][a-z]+-[A-Z][a-z]+
identity [A-Z][0-9]{9,9}
email [0-9]+@[a-z]+((\.[a-z]+)+)?
birthday [0-9]{2,4}\/[0-9]{2,2}\/[0-9]{2,2}
phone \+886[0-9]{9,9}
%option noyywrap
%%
{name}	{if(counter++){cout<<'\n';}ECHO;cout<<'\n';}
{identity} {cout<<"identity number: ";ECHO;cout<<'\n';}
{email} {cout<<"email: ";ECHO;cout<<'\n';}
{birthday} {cout<<"birthday: ";ECHO;cout<<'\n';}
{phone} {cout<<"phone: ";ECHO;cout<<'\n';}
%%
int main() {
    yylex();
    return 0;
}