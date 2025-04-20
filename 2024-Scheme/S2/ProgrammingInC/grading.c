#include <stdio.h>

int main()
{
    float percentage;

    printf("Input your percentage: ");
    scanf("%f", &percentage);

    if (percentage >= 90) {
        printf("S Grade - 10 Grade Points!\n");
    } else if (percentage >= 80) {
        printf("A Grade - 9 Grade Points!\n");
    } else if (percentage >= 70) {
        printf("B Grade - 8 Grade Points!\n");
    } else if (percentage >= 60) {
        printf("C Grade - 7 Grade Points!\n");
    } else if (percentage >= 50) {
        printf("D Grade - 6 Grade Points!\n");
    } else {
        printf("F Grade - 0 Grade Point!\n");
    }

    return 0;
}