/**
 * Day 67 - Question 117
 * 
 * Write a program to take two sorted arrays of size m and n as input. Merge both the arrays such that the merged array is also sorted. Print the merged array.
 * 
 * Test Cases:
 * Test Case 1:
 *   Input: nums1 = [2,7,11,15] nums2 = [4,8,10]
 *   Output: 2 4 7 8 10 11 15
 * Test Case 2:
 *   Input: nums1 = [1,2,7] nums2 = [9,10,17]
 *   Output: 1 2 7 9 10 17
 * Test Case 3:
 *   Input: nums1 = [-10,-2,7] nums2 = [-3, -1, 7]
 *   Output: -10 -3 -2 -1 7 7
 */

#include <stdio.h>

void mergeSorted(int a[], int m, int b[], int n, int res[]) {
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (a[i] <= b[j]) {
            res[k++] = a[i++];
        } else {
            res[k++] = b[j++];
        }
    }
    while (i < m) res[k++] = a[i++];
    while (j < n) res[k++] = b[j++];
}

int main() {
    int m, n;
    if (scanf("%d", &m) != 1) return 0;
    int a[1000];
    for (int i = 0; i < m; i++) scanf("%d", &a[i]);
    if (scanf("%d", &n) != 1) return 0;
    int b[1000];
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    
    int res[2000];
    mergeSorted(a, m, b, n, res);
    for (int i = 0; i < m + n; i++) {
        printf("%d%c", res[i], (i == m + n - 1) ? '\n' : ' ');
    }
    return 0;
}
