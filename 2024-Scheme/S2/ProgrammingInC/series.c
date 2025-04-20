#include <stdio.h>
#include <math.h>

float func(int x, int n) {
    float sum = 0;
    for (int i=1; i <= n; i++) {
        if (i%2 == 0) sum -= (pow(x, i) / i);
        else sum += (pow(x, i) / i);
    }
    return sum;
}


int main() {
    int n, x;

    printf("Enter number of members in the series: ");
    scanf("%d", &n);

    printf("Enter a value for x: ");
    scanf("%d", &x);

    float value = func(x, n);

    printf("Value of the sum of the series is: %.2f\n", value);

}
