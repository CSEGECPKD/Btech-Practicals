%{
#include <stdio.h>
void yyerror(const char *s);
int yylex(void);
%}

%%

S: A B C ;

A: 'a' A | 'a' ;
B: 'b' B | 'b' ;
C: 'c' C | 'c' ;

%%

void yyerror(const char *s) { printf("Invalid string\n"); }

int main() {
    printf("Enter string: ");
    yyparse();
    printf("Valid string\n");
    return 0;
}
