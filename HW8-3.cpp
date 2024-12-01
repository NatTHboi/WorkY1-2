/*
    เมื่อผู้ใช้กรอกตัวเลข ให้โปรแกรมแสดงผลรวมของชุดอนุกรม ที่มีตัวเลข 2 ลำดับก่อนหน้าบวกกัน (อนุกรมฟีโบนัชชี)
    
    Test case:
        8
    Output:
        Series = 1 + 1 + 2 + 3 + 5 + 8 + 13 + 21
        Sum = 54

*/

#include <stdio.h>

int main() {
    int n;
    int a = 1, b = 1;
    int sum = 0;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 0;
    }

    printf("Series = ");

    for (int i = 1; i <= n; ++i) {
        printf("%d", a);
        sum += a;

        if (i < n) {
            printf(" + ");
        }

        int next = a + b;
        a = b;
        b = next;
    }

    printf("\nSum = %d\n", sum);

    return 0;
}