/*
Q64: Find the digit that occurs the most times in an integer number.

Sample Test Cases:
Input 1:
112233
Output 1:
1

Input 2:
887799
Output 2:
7
*/

#include <stdio.h>

int main() {
    long long n;
    if (scanf("%lld", &n) == 1) {
        if (n < 0) n = -n;
        int count[10] = {0};
        if (n == 0) count[0]++;
        while (n > 0) {
            count[n % 10]++;
            n /= 10;
        }
        int max_count = 0;
        int best_digit = 0;
        for (int d = 0; d < 10; d++) {
            if (count[d] > max_count) {
                max_count = count[d];
                best_digit = d;
            }
        }
        printf("%d\n", best_digit);
    }
    return 0;
}
