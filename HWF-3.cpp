/*
    อ่านไฟล์และนำมาแสดงผลข้อมูลบนหน้าจอ

    ข้อมูลภายในไฟล์ a15-3.txt :
        Somchai	19	3.78	Male
        Somjing	18	3.54	Female
        Somjung	20	2.44	Male
    Output:
        Somchai	19	3.78	Male
        Somjing	18	3.54	Female
        Somjung	20	2.44	Male
*/

#include <stdio.h>

int main() {
    FILE *file;
    char name[50], gender[10];
    int age;
    float gpa;

    file = fopen("HwF-3file.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file HwF-3file.txt\n");
        return 1;
    }

    printf("Output:\n");
    while (fscanf(file, "%s %d %f %s", name, &age, &gpa, gender) == 4) {
        printf("%s\t%d\t%.2f\t%s\n", name, age, gpa, gender);
    }

    fclose(file);

    return 0;
}