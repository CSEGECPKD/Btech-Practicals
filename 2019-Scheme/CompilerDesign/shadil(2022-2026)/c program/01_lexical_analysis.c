#include <stdio.h>
#include <string.h>
#include <ctype.h>

char keywords[][10] = {"int", "if", "else", "while", "for", "return"};
char operators[] = "+-*/=%";
char separators[] = "();{}[],";

int isKeyword(const char *word) {
    for (int i = 0; i < 6; i++)
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    return 0;
}

int main() {
    FILE *fp = fopen("input.txt", "r");
    if (!fp) {
        printf("File not found!\n");
        return 1;
    }

    char ch, token[50];
    int i = 0;
    int keywordCount = 0, idCount = 0, numCount = 0, opCount = 0, sepCount = 0;

    printf("\nTOKENS FOUND:\n");
    printf("------------------------------------------------\n");

    while ((ch = fgetc(fp)) != EOF) {
        if (isspace(ch))
            continue;

        if (isalpha(ch)) {
            i = 0;
            token[i++] = ch;
            while (isalnum(ch = fgetc(fp)))
                token[i++] = ch;
            token[i] = '\0';
            ungetc(ch, fp);

            if (isKeyword(token)) {
                printf("<KEYWORD, %s>\n", token);
                keywordCount++;
            } else {
                printf("<IDENTIFIER, %s>\n", token);
                idCount++;
            }
        }
        else if (isdigit(ch)) {
            i = 0;
            token[i++] = ch;
            while (isdigit(ch = fgetc(fp)))
                token[i++] = ch;
            token[i] = '\0';
            ungetc(ch, fp);

            printf("<NUMBER, %s>\n", token);
            numCount++;
        }
        else if (strchr(operators, ch)) {
            printf("<OPERATOR, %c>\n", ch);
            opCount++;
        }
        else if (strchr(separators, ch)) {
            printf("<SEPARATOR, %c>\n", ch);
            sepCount++;
        }
    }

    fclose(fp);

    printf("\nSUMMARY TABLE:\n");
    printf("------------------------------------------------\n");
    printf("Keywords    : %d\n", keywordCount);
    printf("Identifiers : %d\n", idCount);
    printf("Numbers     : %d\n", numCount);
    printf("Operators   : %d\n", opCount);
    printf("Separators  : %d\n", sepCount);

    return 0;
}
