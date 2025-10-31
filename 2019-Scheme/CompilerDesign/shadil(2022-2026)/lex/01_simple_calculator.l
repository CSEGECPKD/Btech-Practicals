%{
#include <stdio.h>
int op2=0;
int op1=0;
char op;

%}
%%
[0-9]+ {if(op1==0){
        op1=atoi(yytext);}
        else{
            op2=atoi(yytext);};}
[+\-*/] {op=yytext[0];}
\n {
    switch(op)
    {
        case '+':
           printf("%d",op1+op2);
           break;
    };
}
%%

int yywrap()
{
    return 1;
}
int main ()
{
    printf("enter the string");
    yylex();
    op1=0;op2=0;

}