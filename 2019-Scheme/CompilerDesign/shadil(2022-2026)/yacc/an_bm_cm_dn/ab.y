%{
#include <stdio.h>
#include <stdlib.h>
void yyerror(char *c);
int yylex(void);
%}

%token  NL;
%%

stmt: S NL {printf("vaild string");exit(0);}
S: 'a'A 'd'| 'a' S 'd';
A: 'b' A 'c' | 'b' 'c';


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