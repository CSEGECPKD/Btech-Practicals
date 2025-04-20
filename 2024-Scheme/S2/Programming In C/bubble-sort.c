#include <stdio.h>

int main() {

    int size;

    printf("How many elements are there to be sorted?: ");
    scanf("%d", &size);

    int nums[size];

    for (int m=0; m<size; m++) {
        printf("Enter Element No. %d: ", m+1);
        scanf("%d", &nums[m]);
    }

    for (int i = 0; i < (size - 1); i++) {
        for (int j = 0; j < size - i - 1; j++) {
            int temp;
            if (nums[j] > nums[j+1]) {
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
}
