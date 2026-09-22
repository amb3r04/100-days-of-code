/*
Q79: Perform diagonal traversal of a matrix.

Sample Test Cases:
Input 1:
3 3
1 2 3
4 5 6
7 8 9
Output 1:
1 2 4 7 5 3 6 8 9
*/

#include <stdio.h>

int main() {
    int r, c;
    if (scanf("%d %d", &r, &c) == 2) {
        int mat[100][100];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) scanf("%d", &mat[i][j]);
        }
        int total = r * c;
        int count = 0;
        for (int line = 0; line < r + c - 1; line++) {
            int start_col = (line < c) ? line : c - 1;
            int start_row = (line < c) ? 0 : line - (c - 1);
            int i = start_row, j = start_col;
            while (i < r && j >= 0) {
                printf("%d%c", mat[i][j], (count == total - 1 ? '\n' : ' '));
                count++;
                i++;
                j--;
            }
        }
    }
    return 0;
}
