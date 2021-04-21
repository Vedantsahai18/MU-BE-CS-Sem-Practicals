//comments 4
%{
#include <stdio.h>
#include <stdbool.h>
int comment_lines = 0;
int constant = 0;
char word [] = "const"; 
%}

%%
"/*".*\n  { ++comment_lines; }
"//".*\n { ++comment_lines; }
[a-zA-Z]+    { if(strcmp(yytext, word)==0) 
                   constant++; } 
.  ;
%%

int main()
{
yylex();
printf("\nNo. of comment=%d", comment_lines);   
printf("\nNo. of constant=%d\n", constant); 

return 0;
}

int yywrap()
{
	return 1;
}

Output:
/*
this is acomment

*/
const keys;
//this is comment
No. of comment=2
No. of constant=1

