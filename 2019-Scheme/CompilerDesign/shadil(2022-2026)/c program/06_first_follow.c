#include <stdio.h>
#include <string.h>

#define MAX 10   // Max non-terminals
#define PROD 10  // Max productions
#define TERM 27  // 26 letters + $

// Non-terminals
char nonTerminals[MAX];              
int numberOfNonTerminals;

// Productions
char productions[PROD][20];          
int numberOfProductions;

// FIRST sets
int first[MAX][26];        
int containsEpsilon[MAX];  

// FOLLOW sets (last column for $)
int follow[MAX][TERM];     

// Get index of non-terminal
int getNonTerminalIndex(char c){
    for(int i=0;i<numberOfNonTerminals;i++)
        if(nonTerminals[i]==c) return i;
    return -1;
}

// Compute FIRST sets
void computeFirst(){
    int changed = 1;
    while(changed){
        changed = 0;
        for(int p=0; p<numberOfProductions; p++){
            int lhs = getNonTerminalIndex(productions[p][0]);
            int i=3; // skip "A->"
            int canProduceEps=1;

            while(productions[p][i]!='\0' && canProduceEps){
                canProduceEps=0;
                char s = productions[p][i];

                if(s>='a' && s<='z'){        // terminal
                    int idx = s-'a';
                    if(!first[lhs][idx]) { first[lhs][idx]=1; changed=1; }
                }
                else if(s=='e'){             // epsilon
                    if(!containsEpsilon[lhs]) { containsEpsilon[lhs]=1; changed=1; }
                    canProduceEps=1;
                }
                else {                        // non-terminal
                    int nt = getNonTerminalIndex(s);
                    for(int k=0;k<26;k++)
                        if(first[nt][k] && !first[lhs][k]) { first[lhs][k]=1; changed=1; }
                    if(containsEpsilon[nt]) canProduceEps=1;
                }
                i++;
            }
            if(canProduceEps && !containsEpsilon[lhs]) { containsEpsilon[lhs]=1; changed=1; }
        }
    }
}

// Compute FOLLOW sets
void computeFollow(){
    follow[0][26] = 1; // Start symbol contains $

    int changed = 1;
    while(changed){
        changed = 0;
        for(int p=0; p<numberOfProductions; p++){
            int lhs = getNonTerminalIndex(productions[p][0]); // A in A->α
            for(int i=3; productions[p][i]!='\0'; i++){
                char B = productions[p][i];
                int Bindex = getNonTerminalIndex(B);
                if(Bindex == -1) continue; // skip terminals

                int j = i+1;
                while(productions[p][j]!='\0'){
                    char s = productions[p][j];
                    if(s>='a' && s<='z'){ // terminal
                        int idx = s-'a';
                        if(!follow[Bindex][idx]) { follow[Bindex][idx]=1; changed=1; }
                        break;
                    } else { // non-terminal
                        int nt = getNonTerminalIndex(s);
                        for(int k=0;k<26;k++)
                            if(first[nt][k] && !follow[Bindex][k]) { follow[Bindex][k]=1; changed=1; }
                        if(containsEpsilon[nt]) j++;
                        else break;
                    }
                }
                if(productions[p][j]=='\0'){ // end or epsilon
                    for(int k=0;k<TERM;k++)
                        if(follow[lhs][k] && !follow[Bindex][k]) { follow[Bindex][k]=1; changed=1; }
                }
            }
        }
    }
}

// Print sets
void printFirst(){
    printf("FIRST sets:\n");
    for(int i=0;i<numberOfNonTerminals;i++){
        printf("%c : { ", nonTerminals[i]);
        for(int j=0;j<26;j++)
            if(first[i][j]) printf("%c ", 'a'+j);
        if(containsEpsilon[i]) printf("ε ");
        printf("}\n");
    }
}

void printFollow(){
    printf("FOLLOW sets:\n");
    for(int i=0;i<numberOfNonTerminals;i++){
        printf("%c : { ", nonTerminals[i]);
        for(int j=0;j<26;j++)
            if(follow[i][j]) printf("%c ", 'a'+j);
        if(follow[i][26]) printf("$ ");
        printf("}\n");
    }
}

int main(){
    printf("Enter number of non-terminals: ");
    scanf("%d", &numberOfNonTerminals);
    printf("Enter non-terminals (single characters, e.g., S A B): ");
    for(int i=0;i<numberOfNonTerminals;i++) scanf(" %c", &nonTerminals[i]);

    printf("Enter number of productions: ");
    scanf("%d", &numberOfProductions);
    printf("Enter productions (format: A->aB or A->e for epsilon):\n");
    for(int i=0;i<numberOfProductions;i++){
        scanf("%s", productions[i]);
    }

    computeFirst();
    computeFollow();
    printFirst();
    printFollow();

    return 0;
}
