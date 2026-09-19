/*
Q74: Find the transpose of a matrix.
Q76: Check if a matrix is symmetric.

Day 37 (19-Sep-2026) / Day 38 (20-Sep-2026)
*/

#include <stdio.h>

int transposeAndCheck(int a[3][3]) {
    int i, j, symmetric = 1;
    printf("\nTranspose of the matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) printf("%d\t", a[j][i]);
        printf("\n");
    }
    // Check whether the original matrix is symmetric
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (a[i][j] != a[j][i]) {
                symmetric = 0;
                break;
            }
        }
        if (symmetric == 0) break;
    }
    return symmetric;
}

int main() {
    int a[3][3] = {
        {1, 2, 3},
        {2, 4, 5},
        {3, 5, 6}
    };
    int isSym = transposeAndCheck(a);
    if (isSym) {
        printf("\nThe matrix is symmetric.\n");
    } else {
        printf("\nThe matrix is not symmetric.\n");
    }
    return 0;
}