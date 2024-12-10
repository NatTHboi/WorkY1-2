/*
    เขียนโปรแกรมหาข้อมูลผู้ที่เกรดเฉลี่ยเยอะที่สุดจากบุคคลในไฟล์ข้อมูล โดยให้แสดงข้อมูลเฉพาะชื่อกับเกรดเฉลี่ยเท่านั้น

    ข้อมูลภายในไฟล์ a15-4.txt :
        Somchai	19	3.78	Male
        Somjing	18	3.54	Female
        Somjung	20	2.44	Male
    Output:
        Somchai, Grade 3.78
*/

#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    char name[50], gender[10], topName[50];
    int age;
    float gpa, maxGPA = -1.0;

    file = fopen("HwF-4file.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file HwF-4file.txt\n");
        return 1;
    }

    while (fscanf(file, "%s %d %f %s", name, &age, &gpa, gender) == 4) {
        if (gpa > maxGPA) {
            maxGPA = gpa;
            strcpy(topName, name);
        }
    }

    fclose(file);

    printf("%s, Grade %.2f\n", topName, maxGPA);

    return 0;
}