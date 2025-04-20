#include <stdio.h>

int main() {
    int num,sum=0;

    printf("Enter a number: ");
    scanf("%d", &num);

    int i = num;

    while (i/10 > 0) {
        sum += i%10;
        i/=10;
    }

    sum += i;

    printf("Sum of digits of %d is %d\n", num, sum);
}