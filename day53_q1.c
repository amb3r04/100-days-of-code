/*
Q103: Calculate the pivot index of this array (left sum == right sum).
If no such index exists, print -1.

Sample Test Cases:
Input 1:
nums = [1,7,3,6,5,6]
Output 1:
3

Input 2:
nums = [1,2,3]
Output 2:
-1
*/

#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) == 1) {
        int arr[1000];
        int total_sum = 0;
        printf("Enter elements: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            total_sum += arr[i];
        }
        int left_sum = 0;
        int pivot = -1;
        for (int i = 0; i < n; i++) {
            if (left_sum == total_sum - left_sum - arr[i]) {
                pivot = i;
                break;
            }
            left_sum += arr[i];
        }
        printf("%d\n", pivot);
    }
    return 0;
}
