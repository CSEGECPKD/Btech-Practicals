#include <stdio.h>

int main()
{
    int a, b, c;
    printf("Input three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    (a<c) ? (
        (a<b) ? printf("%d is the smallest number!\n", a) : printf("%d is the smallest number!\n", b)
    ) : (
        (c<b) ? printf("%d is the smallest number!\n", c) : printf("%d is the smallest number!\n", b)
    );

    return 0;
}