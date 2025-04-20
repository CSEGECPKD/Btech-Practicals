#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void searchString(char *string, char search) {
    bool exists = false;

    for (int j = 0; j < strlen(string); j++) {
        if (string[j] == search) {
            exists = true;
            break;
        }
    }
    if (exists) printf("The character '%c' exists in %s", search, string);
    else printf("The character '%c' DOES NOT exist in %s", search, string);
}

int main() {
    char string[100];
    char search;

    printf("Enter the string: ");

    fgets(string, 100, stdin);

    printf("Enter the character to search for: ");
    scanf("%c", &search);

    searchString(string, search);
}