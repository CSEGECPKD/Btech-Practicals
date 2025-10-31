%{
#include <stdio.h>
#include <stdlib.h>
void yyerror(char *c);
int yylex(void);
%}

%token  type ID   NL  ;
%%
stmt: input NL {printf("vaild string");exit(0);}
input: type ID '('Parma_list ')'
Parma_list:/*Empty*/ | Parma_list ',' param |param;
param:type ID;


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