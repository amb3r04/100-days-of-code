/*
Q27: Write a program to print the sum of the first n odd numbers.

Sample Test Cases:
Input 1:
3
Output 1:
9

Input 2:
5
Output 2:
25
*/

#include <stdio.h>

int main() {
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) == 1) {
        long long sum = 0;
        int odd = 1;
        for (int i = 0; i < n; i++) {
            sum += odd;
            odd += 2;
        }
        printf("%lld\n", sum);
    }
    return 0;
}
