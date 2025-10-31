#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct Expr {
    char op;         // operator (+, -, *, /, =)
    char op1[10];    // operand 1
    char op2[10];    // operand 2
    char res[10];    // result variable
    int flag;        // 1 if already optimized
} expr[20];

int n;

void input() {
    printf("Enter number of expressions: ");
    scanf("%d", &n);
    printf("Enter expressions in form: op op1 op2 res\n");
    printf("Example: + 2 3 a\n");
    printf("For assignment, use = value - var (example: = 5 - a)\n\n");

    for (int i = 0; i < n; i++) {
        scanf(" %c %s %s %s", &expr[i].op, expr[i].op1, expr[i].op2, expr[i].res);
        expr[i].flag = 0;
    }
}

void change(int pos, const char *value) {
    // Replace all later uses of expr[pos].res with value
    for (int i = pos + 1; i < n; i++) {
        if (strcmp(expr[pos].res, expr[i].op1) == 0)
            strcpy(expr[i].op1, value);
        if (strcmp(expr[pos].res, expr[i].op2) == 0)
            strcpy(expr[i].op2, value);
    }
}

void constantPropagation() {
    for (int i = 0; i < n; i++) {
        if ((isdigit(expr[i].op1[0]) && isdigit(expr[i].op2[0])) || expr[i].op == '=') {
            int op1 = atoi(expr[i].op1);
            int op2 = atoi(expr[i].op2);
            int result = 0;

            switch (expr[i].op) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op2 ? op1 / op2 : 0; break;
                case '=': result = op1; break;
            }

            char temp[10];
            sprintf(temp, "%d", result);
            expr[i].flag = 1; // mark as optimized
            change(i, temp);  // replace later uses
        }
    }
}

void output() {
    printf("\nOptimized Code:\n");
    for (int i = 0; i < n; i++) {
        if (!expr[i].flag)
            printf("%c %s %s %s\n", expr[i].op, expr[i].op1, expr[i].op2, expr[i].res);
    }
}

int main() {
    input();
    constantPropagation();
    output();
    return 0;
}
