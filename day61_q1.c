/*
Q111: Find the first negative integer in each subarray of size k.
If no negative exists in a window, print 0.

Sample Test Cases:
Input 1:
arr = [-8, 2, 3, -6, 10], k = 2
Output 1:
-8 0 -6 -6

Input 2:
arr = [12, -1, -7, 8, -15, 30, 16, 28], k = 3
Output 2:
-1 -1 -7 -15 -15 0
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
            int first_neg = 0;
            for (int j = 0; j < k; j++) {
                if (arr[i + j] < 0) {
                    first_neg = arr[i + j];
                    break;
                }
            }
            printf("%d%c", first_neg, (i == n - k ? '\n' : ' '));
        }
    }
    return 0;
}
