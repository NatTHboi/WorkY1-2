/*
    จงเขียนโปรแกรมภาษาซีเพื่อรับข้อมูลจากผู้ใช้เป็นตัวเลข และให้แสดงชุดอนุกรมตามจำนวนตัวเลขที่กรอก พร้อมกับแสดงผลรวมของชุดอนุกรมนี้ 9 + 99 + 999 + 9999 + 9999 + .... เช่น ผู้ใช้กรอกเลข 5 ให้แสดงชุดอนุกรมคือ 9 + 99 + 999 + 9999 + 99999 และแสดงผลรวมคือ 111105
    (โจทย์ข้อนี้ให้ใช้ Do While Loop เท่านั้น)
    
    Test case:
        Enter number :
            5
    Output:
        Series = 9 + 99 + 999 + 9999 + 99999
        Sum = 111105

    Test case:
        Enter number :
            7
    Output:
        Series = 9 + 99 + 999 + 9999 + 99999 + 999999 + 9999999
        Sum = 11111103
*/

#include <stdio.h>

int main() {
    int n, i = 1;
    long long term = 9, sum = 0;

    printf("Enter number: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input. Please enter a positive number.\n");
        return 1;
    }

    printf("Series = ");
    do {
        printf("%lld", term);
        sum += term;
        if (i < n) {
            printf(" + ");
        }
        term = term * 10 + 9;
        i++;
    } while (i <= n);
    
    printf("\nSum = %lld\n", sum);

    return 0;
}