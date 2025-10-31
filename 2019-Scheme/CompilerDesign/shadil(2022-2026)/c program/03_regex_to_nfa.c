#include <stdio.h>

#define MAX_STATES 10
#define SYMBOLS 2      // 'a' and 'b'
#define EPSILON 2      // epsilon treated as a special symbol index

int n; // number of states

int nfa[MAX_STATES][SYMBOLS+1][MAX_STATES]; // original NFA including epsilon
int new_nfa[MAX_STATES][SYMBOLS][MAX_STATES]; // NFA without epsilon
int final[MAX_STATES];       // original final states
int new_final[MAX_STATES];   // final states for new NFA

// ----- Compute epsilon closure -----
void eClosure(int state, int visited[]) {
    visited[state] = 1;
    for(int i=0;i<n;i++){
        if(nfa[state][EPSILON][i] && !visited[i]){
            eClosure(i, visited);
        }
    }
}

// ----- Add transition -----
void addTransition(int from, int symbol, int to){
    new_nfa[from][symbol][to] = 1;
}

int main() {
    int i,j,k;

    // --- 1. Input number of states ---
    printf("Enter number of states: ");
    scanf("%d",&n);

    // --- 2. Input transitions ---
    int t;
    printf("Enter number of transitions (including epsilon): ");
    scanf("%d",&t);

    printf("Symbol: 0='a', 1='b', 2='epsilon'\n");
    for(i=0;i<t;i++){
        int from,symbol,to;
        printf("Transition %d (from symbol to): ", i+1);
        scanf("%d %d %d",&from,&symbol,&to);
        nfa[from][symbol][to] = 1;
    }

    // --- 3. Input final states ---
    int f;
    printf("Enter number of final states: ");
    scanf("%d",&f);
    for(i=0;i<f;i++){
        int state;
        printf("Final state %d: ", i+1);
        scanf("%d",&state);
        final[state] = 1;
    }

    // --- 4. Build new NFA (remove epsilon) ---
    for(i=0;i<n;i++){
        int visited[MAX_STATES] = {0};
        eClosure(i,visited); // compute epsilon closure

        for(int symbol=0;symbol<SYMBOLS;symbol++){ // only 'a' and 'b'
            for(j=0;j<n;j++){
                if(visited[j]){
                    for(k=0;k<n;k++){
                        if(nfa[j][symbol][k]){
                            addTransition(i,symbol,k);
                        }
                    }
                }
            }
        }
    }

    // --- 5. Update final states ---
    for(i=0;i<n;i++){
        int visited[MAX_STATES]={0};
        eClosure(i,visited);
        for(j=0;j<n;j++){
            if(visited[j] && final[j]){
                new_final[i] = 1;
                break;
            }
        }
    }

    // --- 6. Print new NFA ---
    printf("\nNew NFA without epsilon:\n");
 for(i = 0; i < n; i++) {
    for(int symbol = 0; symbol < SYMBOLS; symbol++) {
        int printed = 0;
        for(j = 0; j < n; j++) {
            if(new_nfa[i][symbol][j]) {
                printf("q%d --%c--> q%d\n", i, (symbol==0)?'a':'b', j);
                printed = 1;
            }
        }
        // if nothing printed, do nothing
    }
}

    printf("Final states: ");
    for(i=0;i<n;i++){
        if(new_final[i]) printf("q%d ", i);
    }
    printf("\n");

    return 0;
}