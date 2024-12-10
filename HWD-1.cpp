/*
    ผู้ใช้กรอกชื่อและอายุเข้าไปในระบบจำนวน 2 ครั้ง โดยให้คุณทำการสลับอายุของคน 2 คนนี้ผ่านฟังก์ชันที่คุณเขียนขึ้นมา เช่น นาย ก อายุ 31 ปี และ นาย ข อายุ 20 ปี หลังจากเรียกฟังก์ชันการสลับค่าแล้ว นาย ก จะอายุ 20 ปี และนาย ข จะอายุ 31 ปี
    (กำหนดให้เขียนวิธีการสลับ 2 ค่านี้ โดยใช้ตัวแปรประเภท Pointer เท่านั้น)
    
    Test case:
        Input A
        Name : 
            Yorn
        Age : 
            31
        Input B
        Name : 
            Thane
        Age : 
            20
    Output:
        ** RESULT **
        Name: Yorn (31)
        Name: Thane (20)

        ** SWAP AGE **
        Name: Yorn (20)
        Name: Thane (31)

*/

#include <stdio.h>
#include <string.h>

void swapAges(int *age1, int *age2) {
    int temp = *age1;
    *age1 = *age2;
    *age2 = temp;
}

int main() {
    char name1[50], name2[50];
    int age1, age2;

    printf("Input A\n");
    printf("Name : ");
    scanf("%s", name1);
    printf("Age : ");
    scanf("%d", &age1);

    printf("Input B\n");
    printf("Name : ");
    scanf("%s", name2);
    printf("Age : ");
    scanf("%d", &age2);

    printf("\n** RESULT **\n");
    printf("Name: %s (%d)\n", name1, age1);
    printf("Name: %s (%d)\n", name2, age2);

    swapAges(&age1, &age2);

    printf("\n** SWAP AGE **\n");
    printf("Name: %s (%d)\n", name1, age1);
    printf("Name: %s (%d)\n", name2, age2);

    return 0;
}