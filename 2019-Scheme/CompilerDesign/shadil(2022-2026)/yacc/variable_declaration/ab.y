%{
#include <stdio.h>
#include <stdlib.h>
void yyerror(char *c);
int yylex(void);
%}

%token  type ID NUM  NL  ;
%%
stmt: input NL {printf("vaild string");exit(0);}
input: type ID '=' NUM;


%%

void yyerror(char * s)
{
    printf("invaild string");
    exit(0);
}

int main()
{
    printf("enter the string");
    yyparse();
    return 0;

}