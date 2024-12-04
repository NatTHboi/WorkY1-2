/*
    จงสร้างฟังก์ชันเพื่อหาผลรวมของอนุกรม 1! + (1+2!) + (2+3!) + (3+4!) + (4+5!) + ... โดยโปรแกรมจะทำการรับค่าจำนวนพจน์ของอนุกรมมา และให้คุณสร้างฟังก์ชันในการหาผลรวม เช่น ผู้ใช้กรอกเลข 3 ก็ต้องแสดงผลรวมของอนุกรม 1! + (1+2!) + (2+3!)

    Test case:
        3
    Output:
        Sum = 12

    Test case:
        6
    Output:
        Sum = 888

*/

#include <stdio.h>

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int calculateSeriesSum(int terms) {
    int sum = 0;
    for (int i = 1; i <= terms; i++) {
        sum += (i - 1) + factorial(i);
    }
    return sum;
}

int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of terms must be positive.\n");
        return 1;
    }

    int sum = calculateSeriesSum(n);

    printf("Sum = %d\n", sum);

    return 0;
}