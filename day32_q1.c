/*
Q63: Merge two arrays.

Sample Test Cases:
Input 1:
3
1 2 3
2
4 5
Output 1:
1 2 3 4 5
*/

#include <stdio.h>

int main() {
    int n1, n2;
    if (scanf("%d", &n1) == 1) {
        int arr[2000];
        for (int i = 0; i < n1; i++) scanf("%d", &arr[i]);
        if (scanf("%d", &n2) == 1) {
            for (int i = 0; i < n2; i++) scanf("%d", &arr[n1 + i]);
            int total = n1 + n2;
            for (int i = 0; i < total; i++) {
                printf("%d%c", arr[i], (i == total - 1 ? '\n' : ' '));
            }
        }
    }
    return 0;
}
