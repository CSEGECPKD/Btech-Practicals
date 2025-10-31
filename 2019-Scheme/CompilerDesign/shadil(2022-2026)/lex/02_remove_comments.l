%{
    
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

%}

%%
"//".*
"/*"([^*]|\*+[^*/])*\*+"/"
.   {ECHO;}
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
  



  
}