/*
Q41: Write a program to swap the first and last digit of a number.

Sample Test Cases:
Input 1:
1234
Output 1:
4231

Input 2:
1001
Output 2:
1001
*/

#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Enter a number: ");
    if (scanf("%d", &n) == 1) {
        if (n < 10) {
            printf("%d\n", n);
            return 0;
        }
        int last = n % 10;
        int temp = n;
        int digits = 0;
        while (temp > 0) {
            digits++;
            temp /= 10;
        }
        int pow_val = (int)pow(10, digits - 1);
        int first = n / pow_val;
        int middle = (n % pow_val) / 10;
        int result = last * pow_val + middle * 10 + first;
        printf("%d\n", result);
    }
    return 0;
}
