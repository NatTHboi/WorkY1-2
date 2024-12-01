/*
    ผู้ใช้กรอกจำนวนอาเรย์ที่ต้องการกรอก จากนั้นผู้ใช้ทำการกรอกข้อมูลลงไปในอาเรย์จนครบ และให้คุณแสดงค่าในอาเรย์ที่ไม่มีการซ้ำกันเท่านั้น โดยแสดงผลลัพธ์จากน้อยไปมาก
    
    Test case:
        Input N :
            5
        Input :
            1
        Input :
            1
        Input :
            2
        Input :
            3
        Input :
            3
    Output:
        Unique value : 2

    
    Test case:
        Input N :
            6
        Input :
            9
        Input :
            9
        Input :
            5
        Input :
            6
        Input :
            2
        Input :
            1
    Output:
        Unique value : 1 2 5 6

*/

#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    int n;

    printf("Input N: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input. Please enter a positive number.\n");
        return 1;
    }

    int array[n];
    std::map<int, int> frequency;
    std::vector<int> unique_values;

    for (int i = 0; i < n; ++i) {
        printf("Input: ");
        scanf("%d", &array[i]);
        frequency[array[i]]++;
    }

    for (auto &entry : frequency) {
        if (entry.second == 1) {
            unique_values.push_back(entry.first);
        }
    }

    std::sort(unique_values.begin(), unique_values.end());

    printf("Unique value: ");
    if (unique_values.empty()) {
        printf("No unique values.\n");
    } else {
        for (int value : unique_values) {
            printf("%d ", value);
        }
        printf("\n");
    }

    return 0;
}