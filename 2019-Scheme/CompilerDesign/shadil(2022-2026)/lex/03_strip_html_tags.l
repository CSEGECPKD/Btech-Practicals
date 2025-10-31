%{
    
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

%}

%%
"<"[^>]*">"
[^<] {printf("%s",yytext);}

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
\


  
}