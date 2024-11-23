/*
    จงเรียงลำดับเลขจากข้อมูลที่ผู้ใช้กรอก โดยเรียงจากมากไปน้อย (โดยใช้คำสั่ง if else หรือ else if เท่านั้น)
    
    Test case:
        Input[1] :
            6
        Input[2] :
            9
        Input[3] :
            1
    Output:
        9 6 1

    Test case:
        Input[1] :
            65
        Input[2] :
            91
        Input[3] :
            112
    Output:
        112 91 65
*/

#include <stdio.h>

int main() {
    int a, b, c ;
    printf( "Input[1] : \n" ) ;
    scanf( "%d", &a ) ;
    printf( "Input[2] : \n" ) ;
    scanf( "%d", &b ) ;
    printf( "Input[3] : \n" ) ;
    scanf( "%d", &c ) ;

    if ( a > b && b > c ) {
        printf( "%d %d %d", a, b, c ) ;
    } else if ( a > c && c > b ) {
        printf( "%d %d %d", a, c, b ) ;
    } else if ( b > a && a > c ) {
        printf( "%d %d %d", b, a, c ) ;
    } else if ( b > c && c > a ) {
        printf( "%d %d %d", b, c, a ) ;
    } else if ( c > a && a > b ) {
        printf( "%d %d %d", c, a, b ) ;
    } else if ( c > b && b > a ) {
        printf( "%d %d %d", c, b, a ) ;
    } else {
        printf( "Error" ) ;
    }

    return 0 ;
}