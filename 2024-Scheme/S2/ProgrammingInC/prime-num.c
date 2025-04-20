#include <stdio.h>
#include <math.h>

int main() {
    int num,i=2;

    printf("Enter a number: ");
    scanf("%d", &num);

    int x = sqrt(num);

    while(i <= x) {
        if (num % i == 0) {
            printf("%d is NOT a prime number!\n", num);
            break;
        }

        i++;
    }

    if (i > x) {
        printf("%d is a prime number!\n", num);

    }

    return 0;
}