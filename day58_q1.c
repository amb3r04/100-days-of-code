/*
Q108: Product of Array Except Self.

Sample Test Cases:
Input 1:
nums = [1,2,3,4]
Output 1:
[24,12,8,6]

Input 2:
nums = [-1,1,0,-3,3]
Output 2:
[0,0,9,0,0]
*/

#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) == 1) {
        int arr[1000], left[1000], right[1000];
        printf("Enter elements: ");
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        
        left[0] = 1;
        for (int i = 1; i < n; i++) left[i] = left[i - 1] * arr[i - 1];
        
        right[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) right[i] = right[i + 1] * arr[i + 1];
        
        printf("[");
        for (int i = 0; i < n; i++) {
            int prod = left[i] * right[i];
            printf("%d%s", prod, (i == n - 1 ? "]" : ","));
        }
        printf("\n");
    }
    return 0;
}
