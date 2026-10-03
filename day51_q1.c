/*
Q101: Write a Program to take a sorted array(say nums[]) and an integer (say target) as inputs.
Print the index of first and last occurrence. Print -1, -1 if the target is not present.

Sample Test Cases:
Input 1:
nums = [5,7,7,8,8,10], target = 8
Output 1:
3,4

Input 2:
nums = [5,7,7,8,8,10], target = 6
Output 2:
-1,-1
*/

#include <stdio.h>

int main() {
    int n, target;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) == 1) {
        int arr[1000];
        printf("Enter sorted elements: ");
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        printf("Enter target: ");
        if (scanf("%d", &target) == 1) {
            int first = -1, last = -1;
            for (int i = 0; i < n; i++) {
                if (arr[i] == target) {
                    if (first == -1) first = i;
                    last = i;
                }
            }
            printf("%d,%d\n", first, last);
        }
    }
    return 0;
}
