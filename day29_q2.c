/*
Q58: Find the maximum and minimum element in an array.

Sample Test Cases:
Input 1:
5
2 9 1 4 7
Output 1:
Max=9, Min=1

Input 2:
3
10 10 10
Output 2:
Max=10, Min=10
*/

#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1 && n > 0) {
        int val, max_val, min_val;
        scanf("%d", &val);
        max_val = min_val = val;
        for (int i = 1; i < n; i++) {
            scanf("%d", &val);
            if (val > max_val) max_val = val;
            if (val < min_val) min_val = val;
        }
        printf("Max=%d, Min=%d\n", max_val, min_val);
    }
    return 0;
}
