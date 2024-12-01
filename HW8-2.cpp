/*
    ผู้ใช้กรอกค่า "คะแนนดิบ" เข้ามาในระบบเพื่อต้องการตรวจสอบเกรดในรายวิชา Programming ซึ่งมีเกณฑ์การให้คะแนนคือ F อยู่ในช่วงคะแนนน้อยกว่า 50 , D อยู่ในช่วงระหว่าง 50 ถึง 55 , D+ อยู่ในช่วงระหว่าง 55 ถึง 60 , C อยู่ในช่วงระหว่าง 60 ถึง 65 , C+ อยู่ในช่วงระหว่าง 65 ถึง 70 , B อยู่ในช่วงระหว่าง 70 ถึง 75 , B+ อยู่ในช่วงระหว่าง 75 ถึง 80 , A อยู่ในช่วงคะแนนมากกว่า 80 ขึ้นไป
    (กำหนดให้ข้อนี้ใช้คำสั่ง for แทนคำสั่งเงื่อนไขได้เท่านั้น)
    
    Test case:
        enter score :
            80
    Output:
        A !

    Test case:
        enter score :
            55
    Output:
        D+ !

    Test case:
        enter score :
            64
    Output:
        C !

    Test case:
        enter score :
            44
    Output:
        F !
*/

#include <stdio.h>

int main() {
    int score;
    const char *grade = "F";

    printf("Enter score: ");
    scanf("%d", &score);

    for (int i = 0; i <= 100; ++i) {
        if (score >= 50 && score < 55) grade = "D";
        if (score >= 55 && score < 60) grade = "D+";
        if (score >= 60 && score < 65) grade = "C";
        if (score >= 65 && score < 70) grade = "C+";
        if (score >= 70 && score < 75) grade = "B";
        if (score >= 75 && score < 80) grade = "B+";
        if (score >= 80) grade = "A";
    }

    printf("%s !\n", grade);

    return 0;
}