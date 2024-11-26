/*
    จงรับค่าจากผู้ใชิ และวิเคราะห์ว่าจำนวนดังกล่าวเป็นจำนวนเต็มบวก หรือจำนวนเต็มลบ
    
    Test case:
        Input :
            49

    Output:
        Positive

    Test case:
        Input :
            -90

    Output:
        Negative

*/

#include <stdio.h>

int main() {
    int a ;
    printf("Please enter the number : ") ;
    scanf("%d",&a) ;
    if (a > -1) {
        printf("Positive") ;
    } else if (a < 0) {
        printf("Negative") ;
    } else {
        printf("Error") ;
    }

    return 0 ;
}