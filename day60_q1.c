/*
Q110: Find maximum element in each subarray of size k moving from left to right.

Sample Test Cases:
Input 1:
arr[1, 2, 3, 1, 4, 5, 2, 3, 6], k = 3
Output 1:
3 3 4 5 5 5 6

Input 2:
arr[5, 1, 3, 4, 2], k = 1
Output 2:
5 1 3 4 2
*/

#include <stdio.h>

int main() {
    int n, k;
    printf("Enter number of elements and k: ");
    if (scanf("%d %d", &n, &k) == 2) {
        int arr[1000];
        printf("Enter elements: ");
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        
        for (int i = 0; i <= n - k; i++) {
            int max_val = arr[i];
            for (int j = 1; j < k; j++) {
                if (arr[i + j] > max_val) max_val = arr[i + j];
            }
            printf("%d%c", max_val, (i == n - k ? '\n' : ' '));
        }
    }
    return 0;
}
