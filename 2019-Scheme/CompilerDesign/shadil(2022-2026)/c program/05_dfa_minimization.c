#include <stdio.h>
#include <stdlib.h>

#define STATES 10
#define SYMBOLS 2

int transitions[STATES][SYMBOLS];
int final_states[STATES];
int n_states, n_symbols, n_final;

int distinguishable[STATES][STATES];

int is_final(int state) {
    for (int i = 0; i < n_final; i++)
        if (final_states[i] == state)
            return 1;
    return 0;
}

int main() {
    printf("Enter number of states: ");
    scanf("%d", &n_states);
    printf("Enter number of input symbols: ");
    scanf("%d", &n_symbols);

    printf("Enter transition table (next state for each symbol):\n");
    for (int i = 0; i < n_states; i++) {
        for (int j = 0; j < n_symbols; j++) {
            printf("δ(q%d, %c): ", i, 'a' + j);
            scanf("%d", &transitions[i][j]);
        }
    }

    printf("Enter number of final states: ");
    scanf("%d", &n_final);
    printf("Enter final states: ");
    for (int i = 0; i < n_final; i++)
        scanf("%d", &final_states[i]);

    // Step 1: Mark distinguishable pairs (final vs non-final)
    for (int i = 0; i < n_states; i++) {
        for (int j = 0; j < n_states; j++) {
            if (i < j) {
                if (is_final(i) != is_final(j))
                    distinguishable[i][j] = 1;
                else
                    distinguishable[i][j] = 0;
            }
        }
    }

    // Step 2: Iteratively mark distinguishable pairs
    int changed;
    do {
        changed = 0;
        for (int i = 0; i < n_states; i++) {
            for (int j = 0; j < n_states; j++) {
                if (i < j && !distinguishable[i][j]) {
                    for (int s = 0; s < n_symbols; s++) {
                        int p = transitions[i][s];
                        int q = transitions[j][s];
                        if (p == q) continue;
                        if (p > q) { int tmp = p; p = q; q = tmp; }
                        if (distinguishable[p][q]) {
                            distinguishable[i][j] = 1;
                            changed = 1;
                            break;
                        }
                    }
                }
            }
        }
    } while (changed);

    // Step 3: Print equivalent states
    printf("\nEquivalent States:\n");
    for (int i = 0; i < n_states; i++) {
        for (int j = i + 1; j < n_states; j++) {
            if (!distinguishable[i][j])
                printf("q%d and q%d are equivalent\n", i, j);
        }
    }

    return 0;
}
