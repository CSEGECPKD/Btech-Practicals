%{ 
#include<stdio.h>
#include<stdlib.h>
int yylex(void);
void yyerror(const char* s);
%}

%token A B C NL

%%

input: /* empty */
     | input stmt
     ;

stmt: S NL { printf("valid string\n"); };

S: A S A
 | B S B
 | C
 ;


%%

void yyerror(const char* s){
    printf("invalid string\n");
}

int main()
{
    printf("Enter string:\n");
    yyparse();
    return 0;
}