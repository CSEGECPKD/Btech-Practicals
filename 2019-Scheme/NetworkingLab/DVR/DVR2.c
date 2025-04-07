#include <stdio.h>

#define MAX 10
#define INF 999

int main() {
    int cost[MAX][MAX], dist[MAX][MAX];
    int n, i, j, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter cost matrix (Enter 999 if no edge exists):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            dist[i][j] = cost[i][j];
        }
    }

    // Distance Vector Algorithm
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("Final Distance Vector Table:\n");
    for (i = 0; i < n; i++) {
        printf("From Node %d:\n", i);
        for (j = 0; j < n; j++) {
            printf("To Node %d: %d\n", j, dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}