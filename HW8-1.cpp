/*
    เขียนโปรแกรมรับตัวเลขจากผู้ใช้ n ชุด จากนั้นทำการหาผลรวม และค่าเฉลี่ยของชุดตัวเลขเหล่านั้น (แสดงค่าเฉลี่ยเป็นทศนิยม 2 ตำแหน่ง)
    
    Test case:
        Enter value n :
            6
        Enter number 1 :
            19
        Enter number 2 :
            7
        Enter number 3 :
            23
        Enter number 4 :
            96
        Enter number 5 :
            77
        Enter number 6 :
            16
    Output:
        Sum = 238
        Avg = 39.67

*/

#include <stdio.h>

int main() {
    int n, i, number, sum = 0;
    float average;

    printf("Enter value n :\n");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("Enter number %d :\n", i);
        scanf("%d", &number);
        sum += number;
    }

    average = (float)sum / n;

    printf("Sum = %d\n", sum);
    printf("Avg = %.2f\n", average);

    return 0;
}