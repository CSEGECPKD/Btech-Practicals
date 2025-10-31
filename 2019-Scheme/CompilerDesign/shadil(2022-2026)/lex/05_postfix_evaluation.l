%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int stack[100];
int top =-1;
int op1=0;
int op2=0;
void push(int val)
{
    stack[++top]= val;
}
int pop()
{
    return stack[top--];

}

%}
%%
[0-9]+ {push(atoi(yytext));}
[+\-*/] {
      op2= pop();
      op1=pop();
      switch(yytext[0])
      {
        case '+':
         push(op1+op2);
         break;
        case '-':
         push(op1-op2);
         break;
        case '*':
         push(op1*op2);
         break;
        case '/':
         push(op1/op2);
         break;
      };
}

[ \t]
\n
%%

int yywrap()
{
    return 1;
}
int main ()
{
    printf("enter the string");
    yylex();
    if (top== 0)
    {
        printf("result %d",stack[top]);
    }

}