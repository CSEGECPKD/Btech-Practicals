#include <stdio.h>
#include <string.h>

int main() {

    char str1[100];
    char finalStr[100];

    int wordIndices[10];

    int wordIndexCount = 0;

    printf("Enter the string: ");
    fgets(str1, sizeof(str1), stdin);

    int size = strlen(str1) - 1;


    for (int i=0; i<size; i++) {
        if (str1[i] == ' ') {
            wordIndices[wordIndexCount] =  i - 1    ;

            wordIndexCount++;
        }
    }


    wordIndices[wordIndexCount] = size - 1;
    wordIndexCount++;

    
    int prevWordLastIndex = 0;
    int currentFinalIndex = 0;

    for (int j = 0; j < wordIndexCount; j++) {

        int currentWordLastIndex = wordIndices[j];
        
        for (int k = currentWordLastIndex; k >= prevWordLastIndex; k--) {
            finalStr[currentFinalIndex] = str1[k];
            currentFinalIndex++;
        }

        finalStr[currentFinalIndex] = ' ';
        currentFinalIndex++;

        prevWordLastIndex = currentFinalIndex;

    }

    finalStr[currentFinalIndex] = '\0';

    printf("Reversed word string: %s\n", finalStr);
}