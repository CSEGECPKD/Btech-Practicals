#include <stdio.h>
#include <ctype.h>

char input[100];
int pos = 0;

void E();
void E_prime();

void E() {
    printf("E -> id E'\n");
    if(isalpha(input[pos])) {
        printf("id -> %c\n", input[pos]);
        pos++;
        E_prime();
    } else {
        printf("Syntax Error at position %d: expected identifier\n", pos);
        exit(1);
    }
}

void E_prime() {
    if(input[pos] == '+') {
        printf("E' -> + id E'\n");
        pos++;
        if(isalpha(input[pos])) {
            printf("id -> %c\n", input[pos]);
            pos++;
            E_prime();
        } else {
            printf("Syntax Error at position %d: expected identifier\n", pos);
            exit(1);
        }
    } else {
        printf("E' -> ε\n");
    }
}

int main() {
    printf("Enter input string: ");
    scanf("%s", input);

    E();

    if(input[pos] == '\0')
        printf("Input string is valid.\n");
    else
        printf("Syntax Error: extra symbols at position %d\n", pos);

    return 0;
}