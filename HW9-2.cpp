/*
    ให้ผู้ใช้กรอกค่าเข้ามาเก็บในอาเรย์ จากนั้นให้ทำการแสดงค่าข้อมูล 2 แบบคือ "เรียงข้อมูลจากมากไปน้อย" และ "เรียงข้อมูลจากน้อยไปมาก"
    
    Test case:
        Input : 
            1
        Input : 
            5
        Input : 
            1
        Input : 
            4
        Input : 
            6
        Input : 
            9
        Input : 
            13
        Input : 
            -1
    Output:
        0-99 : 1 1 4 5 6 9 13
        99-0 : 13 9 6 5 4 1 1

*/

#include <stdio.h>
#include <algorithm>

int main() {
    int n = 100;
    int array[n];
    int count = 0;

    for (int i = 0; i < n; ++i) {
        printf("Input: ");
        int value;
        scanf("%d", &value);

        if (value == -1) {
            break;
        }

        array[count++] = value;
    }

    std::sort(array, array + count);

    printf("0-99: ");
    for (int i = 0; i < count; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("99-0: ");
    for (int i = count - 1; i >= 0; --i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}