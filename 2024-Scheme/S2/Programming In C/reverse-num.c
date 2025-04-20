#include <stdio.h>

int main() {
    int num,reverse=0;

    printf("Enter a number: ");
    scanf("%d", &num);

    int i = num;

    while (i/10 > 0) {
        reverse += i%10;
        reverse *= 10;

        i/=10;
    }

    reverse += i;

    printf("Reverse of number %d is %d\n", num, reverse);
}