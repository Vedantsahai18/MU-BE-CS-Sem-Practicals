//count vowels and consonants 1

%{
#include <stdio.h>
int vowels = 0;
int consonants = 0;
%}
%%

[aeiouAEIOU]  vowels++;
[a-zA-Z]  consonants++;
[\n]  ;
.  ;
%%
int main()
{
yylex();
printf ("This Lex program counts the number of vowels and ");
printf ("consonants in given text.");
printf ("\nEnter the text and terminate it with CTRL-d.\n");
printf ("Vowels = %d, consonants = %d.\n", vowels, consonants);
return 0;
}

int yywrap()
{
	return 1;
}
/*
This Lex program counts the number of vowels and consonants in given text.
Enter the text and terminate it with CTRL-d.
apple ball
Vowels = 8, consonants = 14.
*/


