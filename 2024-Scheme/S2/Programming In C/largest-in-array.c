#include <stdio.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        printf("Enter element no. %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int largest = arr[0];

    for (int j = 0; j < n; j++) {
        if (arr[j] > largest) largest = arr[j];
    }

    printf("Largest element in the array is: %d\n", largest);
}
