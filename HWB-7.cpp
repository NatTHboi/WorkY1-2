/*
    เมื่อผู้ใช้กรอกตัวเลข ให้โปรแกรมแสดงผลรวมของชุดอนุกรม ของการหาค่า Factorial โดยมีสูตรในการหาค่า n! = n x (n-1)!
    (! = factorial)
    (จงเขียนในรูปแบบของ Recursion Function)
    
    Test case:
        5
    Output:
        5! = 5 x 4 x 3 x 2 x 1
        5! = 120

    Test case:
        8
    Output:
        8! = 8 x 7 x 6 x 5 x 4 x 3 x 2 x 1
        8! = 40320

*/

#include <stdio.h>

int factorial(int n) {
    if (n == 1 || n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

void displayFactorial(int n) {
    printf("%d! = ", n);
    for (int i = n; i > 0; i--) {
        printf("%d", i);
        if (i > 1) {
            printf(" x ");
        }
    }
    int result = factorial(n);
    printf("\n%d! = %d\n", n, result);
}

int main() {
    int n;

    printf("Enter a number to calculate factorial: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 1;
    }

    displayFactorial(n);

    return 0;
}