/*
Q77: Check if the elements on the diagonal of a matrix are distinct.

Sample Test Cases:
Input 1:
3 3
1 2 3
4 5 6
7 8 1
Output 1:
False

Input 2:
3 3
1 2 3
4 5 6
7 8 9
Output 2:
True
*/

#include <stdio.h>

int main() {
    int r, c;
    if (scanf("%d %d", &r, &c) == 2) {
        int diag[100];
        int diag_len = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int val;
                scanf("%d", &val);
                if (i == j) diag[diag_len++] = val;
            }
        }
        int distinct = 1;
        for (int i = 0; i < diag_len; i++) {
            for (int j = i + 1; j < diag_len; j++) {
                if (diag[i] == diag[j]) {
                    distinct = 0;
                    break;
                }
            }
            if (!distinct) break;
        }
        if (distinct) printf("True\n");
        else printf("False\n");
    }
    return 0;
}
