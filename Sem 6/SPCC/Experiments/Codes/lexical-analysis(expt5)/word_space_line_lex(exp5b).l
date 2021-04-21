//count words, spaces. lines 2
%{ 
#include<stdio.h> 
int lc=0, sc=0, words=0;
%} 
  
/*Rule Section*/
%% 
\n lc++; 
([ ])+ sc++; 
([a-zA-Z0-9])* words++;
%% 
  
int main() 
{ 
    yylex(); 
      
    printf("\nNo. of lines=%d", lc);   
    printf("\nNo. of spaces=%d", sc); 
    printf("\nNo. of words=%d\n", words); 
return 0;
      
} 

int yywrap()
{
	return 1;
}
/*
we r students
we r happy

No. of lines=2
No. of spaces=4
No. of words=6
*/
