#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *b;

    *b = *a;
    *a = temp;
}

int main() {
    int a, b;

    printf("Enter value for a: ");
    scanf("%d", &a);

    printf("Enter value for b: ");
    scanf("%d", &b);

    printf("Values before swapping, a: %d  b: %d\n", a, b);

    swap(&a, &b);

    printf("Values after swapping, a: %d  b: %d\n", a, b);
}