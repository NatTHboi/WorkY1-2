/*
    จากชุดข้อมูลต่อไปนี้ จงเขียนฟังก์ชันเมื่อหาค่ามากที่สุดภายในอาเรย์ โดยที่
        ฟังก์ชันแรก ให้สร้างฟังก์ชันแบบ Pass by value เพื่อหาค่าความสูงที่สุดในอาเรย์ Height
        ฟังก์ชันสอง ให้สร้างฟังก์ชันแบบ Pass by reference เพื่อหาค่าอายุที่มากที่สุดในอาเรย์ Age

    int Height[10] = { 159, 168, 191, 188, 154, 152, 167, 165, 178, 177 } ;
    int Age[10] = { 18, 19, 18, 17, 16, 18, 17, 18, 18, 18 } ;

    Test case:
        
    Output:
        Max Height = 191
        Max Age = 19

*/

#include <stdio.h>

int findMaxHeight(int height[], int size) {
    int max = height[0];
    for (int i = 1; i < size; i++) {
        if (height[i] > max) {
            max = height[i];
        }
    }
    return max;
}

void findMaxAge(int age[], int size, int *maxAge) {
    *maxAge = age[0];
    for (int i = 1; i < size; i++) {
        if (age[i] > *maxAge) {
            *maxAge = age[i];
        }
    }
}

int main() {
    int Height[10], Age[10];
    int size = 10;

    printf("Enter 10 heights:\n");
    for (int i = 0; i < size; i++) {
        printf("Height[%d]: ", i);
        scanf("%d", &Height[i]);
    }

    printf("\nEnter 10 ages:\n");
    for (int i = 0; i < size; i++) {
        printf("Age[%d]: ", i);
        scanf("%d", &Age[i]);
    }

    int maxHeight = findMaxHeight(Height, size);

    int maxAge;
    findMaxAge(Age, size, &maxAge);

    printf("\nMax Height = %d\n", maxHeight);
    printf("Max Age = %d\n", maxAge);

    return 0;
}