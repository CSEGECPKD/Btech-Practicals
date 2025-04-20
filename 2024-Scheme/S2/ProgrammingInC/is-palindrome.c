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

    if (reverse == num) {
        printf("The given number - %d is a palindrome\n", num);
    } else {
        printf("The given number - %d is NOT a palindrome\n", num);
    }

}
