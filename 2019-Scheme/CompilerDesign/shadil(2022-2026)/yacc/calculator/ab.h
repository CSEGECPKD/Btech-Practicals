%{
#include <stdio.h>
#include <stdlib.h>
void yyerror(char *c);
int yylex(void);
%}

%token  PLUS MINUS MUL DIV NUM

%left MINUS PLUS
%left MUL DIV 

%%

expr: expr PLUS expr {printf("%d ",$1 +$3);exit(0); }
    |  expr MINUS expr {printf("%d ",$1 - $3 );}
    |  expr MUL expr {printf("%d ",$1 *$3 );}
    |  expr DIV expr {printf("%d ",$1 / $3) ;}
    | NUM {$$=$1;}
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