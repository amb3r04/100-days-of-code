/*
Q106: Find next greater element for each element in the array.
Print in comma separated fashion.

Sample Test Cases:
Input 1:
arr = [1, 3, 2, 4]
Output 1:
3, 4, 4, -1

Input 2:
arr = [6, 8, 0, 1, 3]
Output 2:
8, -1, 1, 3, -1
*/

#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) == 1) {
        int arr[1000];
        printf("Enter elements: ");
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        for (int i = 0; i < n; i++) {
            int nge = -1;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > arr[i]) {
                    nge = arr[j];
                    break;
                }
            }
            printf("%d%s", nge, (i == n - 1 ? "\n" : ", "));
        }
    }
    return 0;
}
