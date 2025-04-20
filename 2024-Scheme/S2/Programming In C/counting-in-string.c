#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char str1[100];

    printf("Enter the string: ");

    fgets(str1, sizeof(str1), stdin);

    int alphabets = 0,vowels = 0, consonants = 0, spaces = 0;
    char vowelLetters[] = {'a','e','i','o','u','A','E','I','O','U'};

    for (int i = 0; i < strlen(str1); i++) {
        char letter = str1[i];

        if (letter == '\n') continue;

        if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z')) {
            alphabets++;

            bool isVowel = false;
            for (int j=0; j<10; j++) {
                if (letter == vowelLetters[j]) {
                    isVowel = true;
                    break;
                }
            }

            if (isVowel) vowels++;
            else consonants++;
        } else if (letter == ' ') spaces++;
    }

    printf("\nNumber of\n\tAlphabets: %d\n\tVowels: %d\n\tConsonants: %d\n\tSpaces: %d", alphabets, vowels, consonants, spaces);
}
