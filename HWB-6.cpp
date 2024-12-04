/*
    เมื่อผู้ใช้กรอกตัวเลข ให้โปรแกรมแสดงผลรวมของชุดอนุกรม ที่มีตัวเลข 2 ลำดับก่อนหน้าบวกกัน (อนุกรมฟีโบนัชชี)
    (จงเขียนในรูปแบบของ Recursion Function)

    Test case:
        8
    Output:
        Series = 1 + 1 + 2 + 3 + 5 + 8 + 13 + 21
        Sum = 54

*/

#include <stdio.h>

int fibonacci(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibonacciSeriesSum(int terms) {
    int sum = 0;
    printf("Series = ");
    for (int i = 1; i <= terms; i++) {
        int current = fibonacci(i);
        sum += current;
        printf("%d", current);
        if (i != terms) {
            printf(" + ");
        }
    }
    printf("\n");
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

    int sum = fibonacciSeriesSum(n);

    printf("Sum = %d\n", sum);

    return 0;
}