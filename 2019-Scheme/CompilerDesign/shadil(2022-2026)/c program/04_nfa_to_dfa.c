#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STATES 10
#define SYMBOLS 10

int nfa[STATES][SYMBOLS][STATES];
int n_states, n_symbols, start_state, final_states[STATES], n_final;
char symbols[SYMBOLS];

int dfa[100][SYMBOLS];
int dfa_states[100][STATES];
int n_dfa_states = 0;
int dfa_final[100];
int visited[100];

int is_final_state(int state) {
    for (int i = 0; i < n_final; i++)
        if (final_states[i] == state)
            return 1;
    return 0;
}

// Check if a DFA state already exists
int state_exists(int arr[], int size) {
    for (int i = 0; i < n_dfa_states; i++) {
        int match = 1;
        for (int j = 0; j < n_states; j++) {
            if (dfa_states[i][j] != arr[j]) {
                match = 0; break;
            }
        }
        if (match) return i;
    }
    return -1;
}

// Create new DFA state
int add_state(int arr[]) {
    memcpy(dfa_states[n_dfa_states], arr, sizeof(int) * n_states);
    n_dfa_states++;
    return n_dfa_states - 1;
}

int main() {
    printf("Enter number of NFA states: ");
    scanf("%d", &n_states);
    printf("Enter number of input symbols: ");
    scanf("%d", &n_symbols);

    printf("Enter input symbols (e.g. a b): ");
    for (int i = 0; i < n_symbols; i++)
        scanf(" %c", &symbols[i]);

    printf("Enter transition table (use -1 to end transitions for a symbol):\n");
    for (int i = 0; i < n_states; i++) {
        for (int j = 0; j < n_symbols; j++) {
            printf("Transitions from q%d on %c: ", i, symbols[j]);
            int k = 0, x;
            while (1) {
                scanf("%d", &x);
                if (x == -1) break;
                nfa[i][j][k++] = x;
            }
        }
    }

    printf("Enter start state: ");
    scanf("%d", &start_state);
    printf("Enter number of final states: ");
    scanf("%d", &n_final);
    printf("Enter final states: ");
    for (int i = 0; i < n_final; i++)
        scanf("%d", &final_states[i]);

    // Initialize DFA
    int start_arr[STATES] = {0};
    start_arr[start_state] = 1;
    add_state(start_arr);

    // Build DFA states
    for (int i = 0; i < n_dfa_states; i++) {
        if (visited[i]) continue;
        visited[i] = 1;

        for (int s = 0; s < n_symbols; s++) {
            int new_state[STATES] = {0};
            for (int k = 0; k < n_states; k++) {
                if (dfa_states[i][k]) {
                    for (int l = 0; l < STATES; l++) {
                        int t = nfa[k][s][l];
                        if (t >= 0) new_state[t] = 1;
                    }
                }
            }

            int index = state_exists(new_state, n_states);
            if (index == -1)
                index = add_state(new_state);
            dfa[i][s] = index;
        }
    }

    // Determine DFA final states
    for (int i = 0; i < n_dfa_states; i++) {
        for (int j = 0; j < n_states; j++) {
            if (dfa_states[i][j] && is_final_state(j))
                dfa_final[i] = 1;
        }
    }

    // Print DFA transition table
    printf("\nDFA Transition Table:\n");
    for (int i = 0; i < n_dfa_states; i++) {
        printf("DFA State %d {", i);
        for (int j = 0; j < n_states; j++)
            if (dfa_states[i][j]) printf("q%d ", j);
        printf("}");
        if (dfa_final[i]) printf("  <-- Final");
        printf("\n");
        for (int s = 0; s < n_symbols; s++) {
            printf("  on %c --> DFA State %d\n", symbols[s], dfa[i][s]);
        }
    }

    return 0;
}
