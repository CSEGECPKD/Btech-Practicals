#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *eachWord = (char *) calloc(100,1);
    char *eachLine = (char *) calloc(100,1);
    char *largestWord = (char *) calloc(100,1);

    FILE *flptr = fopen("file.txt", "r");

    int largestWordLen = 0;
    int lineCount = 0;

    if (flptr == NULL) {
        printf("Failed to read file\n");
        exit(0);
    }

    while (fscanf(flptr, "%s", eachWord) == 1) {
        
        if (strlen(eachWord) > largestWordLen) {
            largestWordLen = strlen(eachWord);
            strcpy(largestWord, eachWord);
        }
    }

    fseek(flptr, 0, SEEK_SET);

    while (fgets(eachLine, 100, flptr)) lineCount++;

    fclose(flptr);

    printf("Number of lines in file.txt: %d\n", lineCount);
    printf("Largest word is: %s (%d letters)\n", largestWord, largestWordLen);
}