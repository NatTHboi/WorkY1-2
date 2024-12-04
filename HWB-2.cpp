/*
    ผู้ใช้กรอกชื่อและอายุเข้าไปในระบบจำนวน 2 ครั้ง โดยให้คุณทำการสลับอายุของคน 2 คนนี้ผ่านฟังก์ชันที่คุณเขียนขึ้นมา เช่น นาย ก อายุ 31 ปี และ นาย ข อายุ 20 ปี หลังจากเรียกฟังก์ชันการสลับค่าแล้ว นาย ก จะอายุ 20 ปี และนาย ข จะอายุ 31 ปี

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
    struct Person {
        char name[50];
        int age;
    };

    struct Person personA, personB;

    printf("Input A\n");
    printf("Name :\n    ");
    scanf(" %49[^\n]", personA.name);
    printf("Age :\n    ");
    scanf("%d", &personA.age);

    printf("Input B\n");
    printf("Name :\n    ");
    scanf(" %49[^\n]", personB.name);
    printf("Age :\n    ");
    scanf("%d", &personB.age);

    printf("\n** RESULT **\n");
    printf("Name: %s (%d)\n", personA.name, personA.age);
    printf("Name: %s (%d)\n", personB.name, personB.age);

    swapAges(&personA.age, &personB.age);

    printf("\n** SWAP AGE **\n");
    printf("Name: %s (%d)\n", personA.name, personA.age);
    printf("Name: %s (%d)\n", personB.name, personB.age);

    return 0;
}