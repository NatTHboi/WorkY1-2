/*
    จงเขียนโปรแกรมอ่านค่าจากข้อมูลในไฟล์ แล้วนำมาแสดงบนหน้าจอ จากนั้นนำมาเรียงลำดับตามตัวอักษรจาก A-Z และเรียงข้อมูลจาก Z-A

    ข้อมูลภายในไฟล์ a15-8.txt :
        Thai
        Bird
        Ant
        Zero
        Wolf
        Cobra
        Orange
        Mango
        Yoyo
    Output:
        Normal (9 Item): Thai, Bird, Ant, Zero, Wolf, Cobra, Orange, Mango, Yoyo .
        Sort (A to Z)  : Ant, Bird, Cobra, Mango, Orange, Thai, Wolf, Yoyo, Zero .
        Sort (Z to A)  : Zero, Yoyo, Wolf, Thai, Orange, Mango, Cobra, Bird, Ant .
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_LENGTH 50

void sortArray(char arr[][MAX_LENGTH], int count, int ascending);

int main() {
    FILE *file;
    char items[MAX_ITEMS][MAX_LENGTH];
    int count = 0;

    file = fopen("HwF-8file.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file HwF-8file.txt\n");
        return 1;
    }

    while (fscanf(file, "%s", items[count]) != EOF) {
        count++;
    }
    fclose(file);

    printf("Normal (%d Item): ", count);
    for (int i = 0; i < count; i++) {
        printf("%s", items[i]);
        if (i < count - 1) printf(", ");
    }
    printf(" .\n");

    sortArray(items, count, 1);
    printf("Sort (A to Z)  : ");
    for (int i = 0; i < count; i++) {
        printf("%s", items[i]);
        if (i < count - 1) printf(", ");
    }
    printf(" .\n");

    sortArray(items, count, 0);
    printf("Sort (Z to A)  : ");
    for (int i = 0; i < count; i++) {
        printf("%s", items[i]);
        if (i < count - 1) printf(", ");
    }
    printf(" .\n");

    return 0;
}

void sortArray(char arr[][MAX_LENGTH], int count, int ascending) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if ((ascending && strcmp(arr[i], arr[j]) > 0) ||
                (!ascending && strcmp(arr[i], arr[j]) < 0)) {
                char temp[MAX_LENGTH];
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}