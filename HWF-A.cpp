/*
    ดึงข้อมูล Matrix A จากไฟล์ที่ 1 และ Matrix B จากไฟล์ที่ 2 เพื่อนำมาคูณกัน

    ข้อมูลภายในไฟล์ a15-10.txt :
        X	A	B	C
        i	1	2	3
        j	4	5	6
    ข้อมูลภายในไฟล์ b15-10.txt :
        X	A	B
        i	7	8
        j	9	10
        k	11	12
    Output:
        Matrix A from file1 =
        1 2 3
        4 5 6
        Matrix B from file2 =
        7 8
        9 10
        11 12
        Result of A x B =
        58 64
        139 154
*/

#include <stdio.h>

void readMatrix(const char* filename, int matrix[10][10], int* rows, int* cols) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char buffer[256];
    int row = 0, col = 0;

    fgets(buffer, sizeof(buffer), file);

    while (fgets(buffer, sizeof(buffer), file)) {
        col = 0;
        int offset = 0;
        char* line = buffer;
        sscanf(line, "%*s%n", &offset);
        line += offset;
        while (sscanf(line, "%d%n", &matrix[row][col], &offset) == 1) {
            col++;
            line += offset;
        }
        row++;
    }

    *rows = row;
    *cols = col;

    fclose(file);
}

void multiplyMatrices(int A[10][10], int rowsA, int colsA, int B[10][10], int rowsB, int colsB, int result[10][10]) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void printMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[10][10], B[10][10], result[10][10];
    int rowsA, colsA, rowsB, colsB;

    readMatrix("HwF-Afile-1.txt", A, &rowsA, &colsA);
    readMatrix("HwF-Afile-2.txt", B, &rowsB, &colsB);

    if (colsA != rowsB) {
        printf("Matrix multiplication not possible.\n");
        return 1;
    }

    multiplyMatrices(A, rowsA, colsA, B, rowsB, colsB, result);

    printf("Matrix A from file1 =\n");
    printMatrix(A, rowsA, colsA);

    printf("Matrix B from file2 =\n");
    printMatrix(B, rowsB, colsB);

    printf("Result of A x B =\n");
    printMatrix(result, rowsA, colsB);

    return 0;
}
