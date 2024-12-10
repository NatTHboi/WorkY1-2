/*
    ให้เข้าโปรแกรมสุ่มตัวเลขเข้าไปใส่ในตัวแปรอาเรย์ขนาด N ช่อง โดยที่ตัวแปร N คือค่าที่ผู้ใช้กรอกเข้ามา จากนั้นให้คุณเขียนโปรแกรมเพื่อหาค่าที่มากที่สุด และค่าที่น้อยที่สุดภายในตัวแปรอาเรย์นี้ พร้อมทั้งแสดงข้อมูลทุกอย่างภายในอาเรย์ออกมา
    (กำหนดให้ค่าที่สุ่มมา มีช่วงข้อมูลอยู่ที่ 10-99 เท่านั้น)
    (กำหนดให้การแสดงผลแบบชิดขอบขวา 2 ช่องเท่านั้น)

    Test case:
        Input N : 
            11
    Output:
        Index:  0  1  2  3  4  5  6  7  8  9 10
        Array: 99 18 27 16 74 28 43 47 25 10 88

        Max = 99
        Min = 10

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int N;

    printf("Input N : \n");
    scanf("%d", &N);

    if (N <= 0) {
        printf("Invalid size for the array.\n");
        return 1;
    }

    int array[N];

    srand(time(0));

    for (int i = 0; i < N; i++) {
        array[i] = (rand() % 90) + 10;
    }

    int max = array[0];
    int min = array[0];
    for (int i = 1; i < N; i++) {
        if (array[i] > max) {
            max = array[i];
        }
        if (array[i] < min) {
            min = array[i];
        }
    }

    printf("Index: ");
    for (int i = 0; i < N; i++) {
        printf("%2d ", i);
    }
    printf("\n");

    printf("Array: ");
    for (int i = 0; i < N; i++) {
        printf("%2d ", array[i]);
    }
    printf("\n");

    printf("\nMax = %d\n", max);
    printf("Min = %d\n", min);

    return 0;
}