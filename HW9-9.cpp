/*
    ผู้ใช้กรอกจำนวนอาเรย์ 2 มิติขึ้นมา 2 ชุด และกรอกค่าภายในอาเรย์จนครบ จากนั้นให้คุณสร้างอาเรย์ที่ 3 ขึ้นมาเก็บผลรวมของอาเรย์ทั้ง 2 ชุดนี้ โดยกำหนดให้ Element ของ Array1 , Array2 และ Array3 เท่ากัน
    
    Test case:
        Array1 element : 
            3 3
        Input :
            1 2 3
            4 5 6
            7 8 9
        Array2 element : 
            3 3
        Input :
            1 1 1
            1 1 1
            1 1 1
    Output:
        Array1 + Array2 = Array3
            2 3 4
            5 6 7
            8 9 10

*/

#include <stdio.h>

int main() {
    int rows1, cols1, rows2, cols2;

    printf("Array1 element: \n");
    scanf("%d %d", &rows1, &cols1);

    printf("Array2 element: \n");
    scanf("%d %d", &rows2, &cols2);

    if (rows1 != rows2 || cols1 != cols2) {
        printf("Error: Both arrays must have the same dimensions.\n");
        return 1;
    }

    int array1[rows1][cols1], array2[rows2][cols2], array3[rows1][cols1];

    printf("Input Array1:\n");
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            scanf("%d", &array1[i][j]);
        }
    }

    printf("Input Array2:\n");
    for (int i = 0; i < rows2; ++i) {
        for (int j = 0; j < cols2; ++j) {
            scanf("%d", &array2[i][j]);
        }
    }

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            array3[i][j] = array1[i][j] + array2[i][j];
        }
    }

    printf("Array1 + Array2 = Array3\n");
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            printf("%d ", array3[i][j]);
        }
        printf("\n");
    }

    return 0;
}