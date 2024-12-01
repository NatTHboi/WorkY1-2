/*
    จากอาเรย์เดิม ที่มีค่าอยู่ก่อนแล้วคือ { 9, 2, 6, 1, 7 } จงเขียนโปรแกรมเพื่อรับค่าจากผู้ใช้อีก N จำนวน เพื่อนำไปต่อในอาเรย์เดิม และจัดเรียงใหม่จากน้อยไปยังมาก
    
    Test case:
        Enter new element of Array :
            4
        Input :
            3
        Input :
            4
        Input :
            2
        Input :
            5
    Output:
        Old Array: 9 2 6 1 7
        New Array: 1 2 2 3 4 4 5 6 7 9
*/

#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {

    std::vector<int> array = {9, 2, 6, 1, 7};
    

    printf("Old Array: ");
    for (int value : array) {
        printf("%d ", value);
    }
    printf("\n");

    int n;
    printf("Enter new element of Array: ");
    scanf("%d", &n);


    for (int i = 0; i < n; ++i) {
        int new_value;
        printf("Input: ");
        scanf("%d", &new_value);
        array.push_back(new_value);
    }


    std::sort(array.begin(), array.end());


    printf("New Array: ");
    for (int value : array) {
        printf("%d ", value);
    }
    printf("\n");

    return 0;
}