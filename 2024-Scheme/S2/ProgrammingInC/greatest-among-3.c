#include <stdio.h>

int main()
{
    int a, b, c;
    printf("Input three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a > c) {
        if (a > b) {
            printf("%d is the greatest number!\n", a);
        } else {
            printf("%d is the greatest number!\n", b);
        }
    } else {
        if (c > b) {
            printf("%d is the greatest number!\n", c);
        } else {
            printf("%d is the greatest number!\n", b);
        }
    }
}

