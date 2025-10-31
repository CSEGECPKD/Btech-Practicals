%{
#include <stdio.h>
#include <stdlib.h>
void yyerror(char *c);
int yylex(void);
%}

%token ID NUM FOR NL INC ;
%%
stmt: input NL {printf("vaild string");exit(0);}
input: FOR '(' init ';' cond ';' inc ')' '{'stmta '}'
init:ID '=' NUM;
cond: ID '<'NUM;
inc: ID INC
stmta: ID '='ID';';

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