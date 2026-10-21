/**
 * Day 69 - Question 119
 * 
 * Write a program to take an integer array as input. Only one element will be repeated. Print the repeated element. Try to find the result in one single iteration.
 * 
 * Test Cases:
 * Test Case 1:
 *   Input: nums1 = [1,3,3,4]
 *   Output: 3
 * Test Case 2:
 *   Input: nums1 = [1,2,2]
 *   Output: 2
 * Test Case 3:
 *   Input: nums1 = [0,4,1,1,5]
 *   Output: 1
 */

#include <stdio.h>

#define MAX_VAL 1000005
static int visited[MAX_VAL];

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int repeated = -1;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x >= 0 && x < MAX_VAL && visited[x]) {
            if (repeated == -1) repeated = x;
        } else if (x >= 0 && x < MAX_VAL) {
            visited[x] = 1;
        }
    }
    printf("%d\n", repeated);
    return 0;
}
