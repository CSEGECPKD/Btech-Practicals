#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

void pop() {
    if(top >= 0) top--;
}

int main() {
    char input[100];
    int i = 0;

    printf("Enter input string (e.g., a+b+c): ");
    scanf("%s", input);

    printf("\nStack\tInput\tAction\t\tProduction Applied\n");
    printf("--------------------------------------------------------\n");

    // REDUCE
while(input[i] != '\0') {
    // SHIFT
    push(input[i]);
    printf("%s\t%s\tShift\t\t-\n", stack, &input[i+1]);
    i++;

    // REDUCE as long as possible
    int reduced = 1;
    while(reduced) {
        reduced = 0;
        if(top >= 2 && stack[top-2]=='E' && stack[top-1]=='+' && islower(stack[top])) {
            stack[top-2] = 'E';
            top -= 2; // remove + and id
            printf("%s\t%s\tReduce\t\tE -> E+id\n", stack, &input[i]);
            reduced = 1;
        }
        else if(top >= 0 && islower(stack[top])) {
            stack[top] = 'E';
            printf("%s\t%s\tReduce\t\tE -> id\n", stack, &input[i]);
            reduced = 1;
        }
    }
}


    

    // Final acceptance check
    if(top == 0 && stack[top] == 'E')
        printf("%s\t%s\tAccept\t\tStart Symbol E\n", stack, &input[i]);
    else
        printf("%s\t%s\tError\t\tParsing Failed\n", stack, &input[i]);

    return 0;
}