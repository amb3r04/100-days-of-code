/*
Q73: Find the sum of each row of a matrix and store it in an array.

Sample Test Cases:
Input 1:
2 3
1 2 3
4 5 6
Output 1:
6 15
*/

#include <stdio.h>

int main() {
    int r, c;
    if (scanf("%d %d", &r, &c) == 2) {
        int row_sums[100];
        for (int i = 0; i < r; i++) {
            int sum = 0, val;
            for (int j = 0; j < c; j++) {
                scanf("%d", &val);
                sum += val;
            }
            row_sums[i] = sum;
        }
        for (int i = 0; i < r; i++) {
            printf("%d%c", row_sums[i], (i == r - 1 ? '\n' : ' '));
        }
    }
    return 0;
}
