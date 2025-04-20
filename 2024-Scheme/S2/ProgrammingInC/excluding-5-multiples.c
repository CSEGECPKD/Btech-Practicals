#include <stdio.h>

int main()
{
    int m, n;
    printf("Input start and ending numbers: ");
    scanf("%d %d", &m, &n);

    for (int i = m; i <= n; i++) {
        if (i % 5 != 0) printf("%d\n", i);
    }

    return 0;
}
