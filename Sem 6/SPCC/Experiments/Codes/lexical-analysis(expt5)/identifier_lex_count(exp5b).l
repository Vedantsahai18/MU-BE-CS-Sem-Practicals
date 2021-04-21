//count c identifiers 3
%{
#include <stdio.h>
int valid = 0;
int invalid = 0;
%}
digit[0-9#_]
letter[a-zA-Z]
%%
{letter}({letter}|{digit})* valid++ ; 
  
{digit}({letter}|{digit})* invalid++ ; 
[\n]  ;
. ;
%%

int main()
{
yylex();
printf("\nNo. of valid=%d", valid);   
printf("\nNo. of invalid=%d", invalid); 

return 0;
}

int yywrap()
{
	return 1;
}
/*
elvis
#shubham
8aditya
_elvis
No. of valid=1
No. of invalid=3
*/
