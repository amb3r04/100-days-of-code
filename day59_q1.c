/*
Q109: Print the maximum sum of all subarrays of size k.

Sample Test Cases:
Input 1:
arr[100, 200, 300, 400], k = 2
Output 1:
700

Input 2:
arr[1, 4, 2, 10, 23, 3, 1, 0, 20], k = 4
Output 2:
39
*/

#include <stdio.h>

int main() {
    int n, k;
    printf("Enter number of elements and k: ");
    if (scanf("%d %d", &n, &k) == 2) {
        int arr[1000];
        printf("Enter elements: ");
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        if (n < k) return 0;
        
        long long window_sum = 0;
        for (int i = 0; i < k; i++) window_sum += arr[i];
        
        long long max_sum = window_sum;
        for (int i = k; i < n; i++) {
            window_sum += arr[i] - arr[i - k];
            if (window_sum > max_sum) max_sum = window_sum;
        }
        printf("%lld\n", max_sum);
    }
    return 0;
}
