/*
    จงอ่านค่าที่ได้จากไฟล์นำมาเพื่อนำมาคำนวณหาผลรวมที่ได้รับจากผู้ใช้

    ข้อมูลภายในไฟล์ a15-2.txt
        2

    Test case:
        Input vale from user to B:
            12
    Output:
        Read File to A is 2
        Input value from user is 12
        Answer = 14

    Test case:
        Input vale from user to B:
            20
    Output:
        Read File to A is 2
        Input value from user is 20
        Answer = 22
*/

#include <stdio.h>

int main() {
    FILE *file;
    int A, B, answer;

    file = fopen("HwF-2file.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file HwF-2file.txt\n");
        return 1;
    }

    if (fscanf(file, "%d", &A) != 1) {
        printf("Error: Could not read an integer from file HwF-2file.txt\n");
        fclose(file);
        return 1;
    }
    fclose(file);

    printf("Read File to A is %d\n", A);

    printf("Input value from user to B: ");
    scanf("%d", &B);

    answer = A + B;

    printf("Input value from user is %d\n", B);
    printf("Answer = %d\n", answer);

    return 0;
}