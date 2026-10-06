/*
Q104: Find the pivot integer x such that sum(1..x) == sum(x..n).
Print x, or -1 if no such integer exists.

Sample Test Cases:
Input 1:
n = 8
Output 1:
6

Input 2:
n = 1
Output 2:
1

Input 3:
n = 4
Output 3:
-1
*/

#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) == 1) {
        long long total = (long long)n * (n + 1) / 2;
        long long sq = (long long)sqrt(total);
        if (sq * sq == total) {
            printf("%lld\n", sq);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}
