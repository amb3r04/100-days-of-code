/*
Q5: Write a program to convert temperature from Celsius to Fahrenheit.

Sample Test Cases:
Input 1:
0
Output 1:
Fahrenheit=32

Input 2:
100
Output 2:
Fahrenheit=212
*/

#include <stdio.h>

int main() {
    float c, f;
    printf("Enter temperature in Celsius: ");
    if (scanf("%f", &c) == 1) {
        f = (c * 9.0 / 5.0) + 32.0;
        if (f == (int)f) {
            printf("Fahrenheit=%d\n", (int)f);
        } else {
            printf("Fahrenheit=%.2f\n", f);
        }
    }
    return 0;
}
