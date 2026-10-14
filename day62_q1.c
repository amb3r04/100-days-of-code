/*
Q112: Maximum sum of contiguous subarray using Kadane's algorithm.

Sample Test Cases:
Input 1:
arr = [2, 3, -8, 7, -1, 2, 3]
Output 1:
11

Input 2:
arr = [-2, -4]
Output 2:
-2
*/

#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) == 1 && n > 0) {
        int arr[1000];
        printf("Enter elements: ");
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        
        long long max_so_far = arr[0];
        long long curr_max = arr[0];
        for (int i = 1; i < n; i++) {
            curr_max = (arr[i] > curr_max + arr[i]) ? arr[i] : curr_max + arr[i];
            if (curr_max > max_so_far) max_so_far = curr_max;
        }
        printf("%lld\n", max_so_far);
    }
    return 0;
}
