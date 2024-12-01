/*
    ผู้ใช้กรอกค่าจำนวนที่ต้องการสร้างอาเรย์ พร้อมกับกรอกค่าภายในอาเรย์จนครบ จากนั้นให้คุณแสดงค่าที่มาก "เป็นอันดับสาม" ของภายในอาเรย์
    
    Test case:
        Enter new element of Array :
            5
        Input :
            5
        Input :
            3
        Input :
            2
        Input :
            1
        Input :
            9           
    Output:
        Array: 5 3 2 1 9
        The large 3rd element = 3

    Test case:
        Enter new element of Array :
            8
        Input :
            6
        Input :
            7
        Input :
            11
        Input :
            13
        Input :
            15
        Input :
            49
        Input :
            27
        Input :        
            18
    Output:
        Array: 6 7 11 13 15 49 27 18
        The large 3rd element = 18
*/

#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
    int n;

    printf("Enter new element of Array: ");
    scanf("%d", &n);

    if (n < 3) {
        printf("Error: Array size must be at least 3 to find the 3rd largest element.\n");
        return 1;
    }

    std::vector<int> array(n);

    for (int i = 0; i < n; ++i) {
        printf("Input: ");
        scanf("%d", &array[i]);
    }

    printf("Array: ");
    for (int value : array) {
        printf("%d ", value);
    }
    printf("\n");

    std::sort(array.begin(), array.end(), std::greater<int>());

    printf("The large 3rd element = %d\n", array[2]);

    return 0;
}