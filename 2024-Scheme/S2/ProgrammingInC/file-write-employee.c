#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    
    int n;

    FILE *fileptr = fopen("employees.txt", "w");

    printf("Enter number of employees: ");
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        int id;
        char name[20];
        char designation[20];

        printf("\nEnter details of Employee %d:\n", i+1);

        printf("Enter ID: ");
        scanf("%d", &id);

        printf("Enter Name: ");
        scanf("%s", name);

        printf("Enter Designation: ");
        scanf("%s", designation);

        fprintf(fileptr, "%s %d\n%s %s\n%s %s\n\n", "ID: ", id,"Name: " ,name,"Designation: ", designation);
    }

    fclose(fileptr);
}