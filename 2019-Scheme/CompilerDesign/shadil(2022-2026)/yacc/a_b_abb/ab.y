%{
#include <stdio.h>
#include<stdlib.h>
void yyerror(const char *s);
int yylex(void);
%}

%%

S: A 'a' 'b' 'b' ;
A:/* empty */ | 'a'A | 'b'A;

%%

void yyerror(const char *s) {
    printf("Invalid string\n");
    exit(0);
}

int main() {
    printf("Enter string: ");
    yyparse();
    printf("Valid string\n");
    return 0;
}
