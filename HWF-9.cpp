/*
    จงเขียนโปรแกรมเพื่อถอดรหัสข้อมูลจากไฟล์ และแปลงเป็นภาษาอังกฤษให้ถูกต้อง โดยโค๊ดที่อ่านได้จากไฟล์คือภาษาอังกฤษที่ถูกเลื่อนไปทางขวา 6 ตัวอักษร (เข้าไปที่เว็บไซท์นี้ https://studio.code.org/s/hoc-encryption/stage/1/puzzle/1 และทำการเลื่อนตัวอักษรไปทางขวา 6 ครั้ง จะได้รหัสลับนี้มา
    ดูวีดีโอประกอบได้ที่ลิงค์นี้ https://www.youtube.com/watch?v=eN4coe9KKzE

    ข้อมูลภายในไฟล์ a15-9.txt :
        C UG ALIIN
    Output:
        Output: I AM GROOT
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void decrypt_caesar_cipher(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char shift_base = isupper(text[i]) ? 'A' : 'a';
            text[i] = (text[i] - shift_base - shift + 26) % 26 + shift_base;
        } else if (text[i] == ' ') {
            continue;
        }
    }
}

int main() {
    const char *input_filename = "HwF-9file.txt";
    FILE *file = fopen(input_filename, "r");

    if (file == NULL) {
        printf("Error: file not found %s\n", input_filename);
        return 1;
    }

    char encoded_text[256];
    if (fgets(encoded_text, sizeof(encoded_text), file) != NULL) {
        encoded_text[strcspn(encoded_text, "\n")] = '\0';

        printf("Input: %s\n", encoded_text);

        int shift = 20;
        decrypt_caesar_cipher(encoded_text, shift);

        printf("Output: %s\n", encoded_text);
    } else {
        printf("Error: Can't read the file infomation\n");
    }

    fclose(file);
    return 0;
}