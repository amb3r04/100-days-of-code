/*
Q68: Delete an element from an array.

Sample Test Cases:
Input 1:
5
1 2 3 4 5
2
Output 1:
1 2 4 5
*/

#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int arr[1000];
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        int pos;
        if (scanf("%d", &pos) == 1) {
            for (int i = pos; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }
            int total = n - 1;
            for (int k = 0; k < total; k++) {
                printf("%d%c", arr[k], (k == total - 1 ? '\n' : ' '));
            }
        }
    }
    return 0;
}
