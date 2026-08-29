/*
Q39: Write a program to find the product of odd digits of a number.

Sample Test Cases:
Input 1:
12345
Output 1:
15

Input 2:
2468
Output 2:
1
*/

#include <stdio.h>

int main() {
    int n;
    printf("Enter a number: ");
    if (scanf("%d", &n) == 1) {
        if (n < 0) n = -n;
        int prod = 1;
        int has_odd = 0;
        while (n > 0) {
            int digit = n % 10;
            if (digit % 2 != 0) {
                prod *= digit;
                has_odd = 1;
            }
            n /= 10;
        }
        if (!has_odd) prod = 1;
        printf("%d\n", prod);
    }
    return 0;
}
