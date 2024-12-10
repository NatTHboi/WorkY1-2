/*
    จงเขียนโปรแกรมเพื่ออ่านค่าจากไฟล์ a15-1.txt แล้วนำมาแสดงผลบนโปรแกรม

    ข้อมูลภายในไฟล์ a.txt
        Hello World
    
    Output:
        Text in file = Hello World
*/

#include <stdio.h>

int main() {
    FILE *file;
    char buffer[256];

    file = fopen("HwF-1file.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file a15-1.txt\n");
        return 1;
    }

    if (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("Text in file = %s\n", buffer);
    } else {
        printf("Error: Could not read from file a15-1.txt\n");
    }

    fclose(file);

    return 0;
}