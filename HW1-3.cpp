/*
    เขียนโปรแกรมรับ "ชื่อ" จากผู้ใช้ และแสดงผลบนหน้าจอดังผลลัพธ์ด้านล่างต่อไปนี้

    Test case:
        First Name: Aomsin
        Last Name: AomMoney
    Output:
        Aomsin AomMoneys TC, RMUTL, Chiang Mai, Thailand

    Test case:
        First Name: ABC
        Last Name: DEF
    Output:
        ABD DEFs TC, RMUTL, Chiang Mai, Thailand
*/
#include <stdio.h>
int main() {
    char a[99] ;
    char b[99] ;
    printf( "First Name: " ) ;
    scanf( "%s", a ) ;
    printf( "Last Name: ") ;
    scanf( "%s", b ) ;
    printf( "%s %ss TC, RMUTL, Chiang Mai, Thailand", a, b ) ;

    return 0 ;
}
