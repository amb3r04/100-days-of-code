/*
Q107: Find previous greater element for each element in the array.
Print in comma separated fashion.

Sample Test Cases:
Input 1:
arr = [1, 3, 2, 4]
Output 1:
-1, -1, 3, -1

Input 2:
arr = [6, 8, 0, 1, 3]
Output 2:
-1, -1, 8, 8, 8
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
            int pge = -1;
            for (int j = i - 1; j >= 0; j--) {
                if (arr[j] > arr[i]) {
                    pge = arr[j];
                    break;
                }
            }
            printf("%d%s", pge, (i == n - 1 ? "\n" : ", "));
        }
    }
    return 0;
}
