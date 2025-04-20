#include <stdio.h>

void readMatrix(int * mat, int row, int col) {

    for (int i=0; i < row; i++) {
        for (int j=0; j < row; j++) {
            printf("Enter value at position %d %d: ", i, j);
            scanf("%d", mat + (i*col) + j);
        }
    }

    // printf("%d\n", mat[1][0]);

}

void addMatrices(int * mat1, int row1, int col1, int * mat2, int row2, int col2) {

    if (row1 != row2 || col1 != col2) {
        printf("The matrices are incompatible");
        return;
    }

    int mat3[row1][col1];

    // Addition
    for (int i=0; i < row1; i++) {
        for (int j=0; j < row1; j++) {
            mat3[i][j] = *(mat1 + (i*col1) + j) + *(mat2 + (i*col1) + j);
        }
    }

    printf("%d",mat3[0][0]);

    // for (int i=0; i < row1; i++) {
    //     for (int j=0; j < row1; j++) printf("%d", mat3[i][j]);
    //     printf("\n");
    // }

    
}

int main() {
    int row1;
    int col1;
    printf("Enter value for number of rows for matrix 1: ");
    scanf("%d", &row1);

    printf("Enter value for number of cols for matrix 1: ");
    scanf("%d", &col1);

    int matA[row1][col1];
    
    readMatrix((int *)matA, row1, col1);


    int row2;
    int col2;
    printf("Enter value for number of rows for matrix 2: ");
    scanf("%d", &row2);

    printf("Enter value for number of cols for matrix 2: ");
    scanf("%d", &col2);

    int matB[row2][col2];
    
    readMatrix((int *)matA, row2, col2);


    addMatrices((int *)matA, row1, col1, (int *)matB, row2, col2);
}