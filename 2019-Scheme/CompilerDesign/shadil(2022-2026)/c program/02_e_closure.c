#include <stdio.h>

#define MAX_STATES 10

int nfa[MAX_STATES][MAX_STATES];  // nfa[i][j] = 1 if epsilon transition from i → j
int visited[MAX_STATES];          // track visited states
int n;                            // number of states

// Recursive function to compute ε-closure
void eClosure(int state) {
    visited[state] = 1; // mark current as visited
    for (int j = 0; j < n; j++) {
        // if there's an epsilon transition and not yet visited
        if (nfa[state][j] == 1 && visited[j] == 0) {
            eClosure(j);
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter number of states in NFA: ");
    scanf("%d", &n);

    printf("Enter epsilon transitions (0 or 1) in matrix form:\n");
    printf("(1 means epsilon transition from row→column)\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &nfa[i][j]);
        }
    }

    printf("Enter start state for ε-closure (0 to %d): ", n - 1);
    scanf("%d", &start);

    // Initialize visited[]
    for (i = 0; i < n; i++) visited[i] = 0;

    // Compute closure
    eClosure(start);

    printf("\nEpsilon-closure of state %d = { ", start);
    for (i = 0; i < n; i++) {
        if (visited[i])
            printf("q%d ", i);
    }
    printf("}\n");

    return 0;
}