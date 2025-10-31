#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100]; // operator stack
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
char peek() { return stack[top]; }
int isEmpty() { return top == -1; }

int precedence(char op) {
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    return 0;
}

void infixToPostfix(char *infix, char *postfix) {
    int k = 0;
    for(int i=0; infix[i]; i++) {
        char c = infix[i];
        if(isalpha(c)) postfix[k++] = c;        // operand
        else if(c=='(') push(c);
        else if(c==')') {
            while(!isEmpty() && peek()!='(') postfix[k++] = pop();
            pop(); // remove '('
        } else { // operator
            while(!isEmpty() && precedence(peek()) >= precedence(c))
                postfix[k++] = pop();
            push(c);
        }
    }
    while(!isEmpty()) postfix[k++] = pop();
    postfix[k] = '\0';
}

// Generate 3-Address Code from postfix
void generate3AC(char *postfix) {
    char tempStack[100]; // stack for operands
    int topTemp = -1;
    int tempCount = 0;

    for(int i=0; postfix[i]; i++) {
        char c = postfix[i];
        if(isalpha(c)) tempStack[++topTemp] = c; // push operand
        else { // operator
            char op2 = tempStack[topTemp--];
            char op1 = tempStack[topTemp--];
            char temp = 't' + tempCount++;
            printf("%c = %c %c %c\n", temp, op1, c, op2);
            tempStack[++topTemp] = temp;
        }
    }
    printf("Result stored in: %c\n", tempStack[topTemp]);
}

int main() {
    char infix[100], postfix[100];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    printf("Three-Address Code:\n");
    generate3AC(postfix);

    return 0;
}
