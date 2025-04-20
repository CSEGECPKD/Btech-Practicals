#include <stdio.h>

int main()
{
    int a, x;
    printf("Input 2 numbers: ");
    scanf("%d %d", &a, &x);

    if (a % x == 0)
    {
        printf("%d is divisible by %d\n", a, x);
    } else {
        printf("%d is NOT divisible by %d\n", a, x);
    }

    return 0;
}