%{
#include <stdio.h>
#include<stdlib.h> 
void yyerror(const char* s);
int yylex(void);
%}

%token  NL

%%
input: /*empty*/ | input stmt;
stmt: S NL {printf("vaild string\n");}
S: A B;
A:/* empty */ | 'a' A ;
B:/* empty */  |'b' B;


%%
void yyerror(const char* s){
 printf("invalid string");
}


int main()
{
    printf("Enter string:\n");
    yyparse();
    

  
}



