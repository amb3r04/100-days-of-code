/*
Q69: Find the second largest element in an array.

Sample Test Cases:
Input 1:
5
10 20 30 40 50
Output 1:
40
*/

#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1 && n >= 2) {
        int first = INT_MIN, second = INT_MIN;
        for (int i = 0; i < n; i++) {
            int val;
            scanf("%d", &val);
            if (val > first) {
                second = first;
                first = val;
            } else if (val > second && val < first) {
                second = val;
            }
        }
        printf("%d\n", second);
    }
    return 0;
}
