#include <stdio.h>

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    int spaces = 2* (n - 1);


    for (int i = 0; i < n; i++) {
        for (int k = 0; k < spaces; k++) printf(" ");

        for (int j = 0; j < (2*i + 1); j++) {
            printf("* ");
        }

        printf("\n");

        spaces -= 2;
    }
}