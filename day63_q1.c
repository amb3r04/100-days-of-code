/*
Q113: Find the kth smallest element in the array.

Sample Test Cases:
Input 1:
arr = [10, 5, 4, 3, 48, 6, 2, 33, 53, 10], k = 4
Output 1:
5

Input 2:
arr = [7, 10, 4, 3, 20, 15], k = 3
Output 2:
7
*/

#include <stdio.h>

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}

int main() {
    int n, k;
    printf("Enter number of elements and k: ");
    if (scanf("%d %d", &n, &k) == 2) {
        int arr[1000];
        printf("Enter elements: ");
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        sort(arr, n);
        if (k >= 1 && k <= n) {
            printf("%d\n", arr[k - 1]);
        }
    }
    return 0;
}
