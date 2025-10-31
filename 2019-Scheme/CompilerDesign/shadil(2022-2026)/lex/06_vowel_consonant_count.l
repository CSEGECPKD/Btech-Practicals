%{
    
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int w=0;
int c=0;
int l=0;
%}

%%
[AEIUOaeiou] {w++;l++;}
[a-zA-Z] { c++;l++;}
[ \t]
\n 

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
  
  printf("the no of vowles %d \n",w);
  printf("the no of cosntonents %d \n",c);
    printf("the no of cosntonents %d \n",l);


  
}