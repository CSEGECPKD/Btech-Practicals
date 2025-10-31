%{
    
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int w=0;
int c=0;
int l=0;
%}

%%
[a-zA-z]+ {w++; c+=strlen(yytext);}
[ \t]
 \n {l++;}

%%

int yywrap()
{
    return 1;

}

int main ()
{
  FILE * fp = fopen("input.txt","r");
  yyin=fp;
  yylex();
  
  printf("the no of words %d \n",w);
  printf("the no of character %d \n",c);
  printf("the no of lines %d \n",l);

  
}