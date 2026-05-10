#include <stdio.h>
void convertToSparse(int matrix[][10], int row, int col, int sparse[][3]) {
    int k = 1, count = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
                count++;
            }
        }
    }
    sparse[0][0] = row;
    sparse[0][1] = col;
    sparse[0][2] = count;
}
void printSparse(int sparse[][3], int size) {
    printf("\nSparse Matrix Representation:\n");
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}
int main() {
    int row, col;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &row, &col);
    int matrix[10][10];
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int sparse[100][3];
    convertToSparse(matrix, row, col, sparse);
    printSparse(sparse, sparse[0][2] + 1);
    return 0;
}
