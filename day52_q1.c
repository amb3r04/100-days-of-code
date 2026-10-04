/*
Q102: Find the index (0-based) of the smallest element in arr[] that is >= x (ceil of x).
If not found, print -1.

Sample Test Cases:
Input 1:
arr = [1, 2, 8, 10, 11, 12, 19], x = 5
Output 1:
2

Input 2:
arr = [1, 2, 8, 10, 11, 12, 19], x = 20
Output 2:
-1
*/

#include <stdio.h>

int main() {
    int n, x;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) == 1) {
        int arr[1000];
        printf("Enter elements: ");
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        printf("Enter x: ");
        if (scanf("%d", &x) == 1) {
            int ceil_idx = -1;
            for (int i = 0; i < n; i++) {
                if (arr[i] >= x) {
                    ceil_idx = i;
                    break;
                }
            }
            printf("%d\n", ceil_idx);
        }
    }
    return 0;
}
