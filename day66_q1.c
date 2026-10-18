/**
 * Day 66 - Question 116
 * 
 * Write a program to take an integer array nums which contains only positive integers, and an integer target as inputs. The goal is to find two distinct indices i and j in the array such that nums[i] + nums[j] equals the target. Assume exactly one solution exists and return the indices in any order. Print the two indices separated by a space as output. If no solution exists, print "-1 -1".
 * 
 * Test Cases:
 * Test Case 1:
 *   Input: nums = [2,7,11,15], target = 9
 *   Output: 0 1
 *   Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 * Test Case 2:
 *   Input: nums = [3,2,4], target = 6
 *   Output: 1 2
 * Test Case 3:
 *   Input: nums = [3,3], target = 6
 *   Output: 0 1
 */

#include <stdio.h>

int main() {
    int n, target;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    int nums[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    scanf("%d", &target);
    
    int found = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                printf("%d %d\n", i, j);
                found = 1;
                break;
            }
        }
        if (found) break;
    }
    if (!found) {
        printf("-1 -1\n");
    }
    return 0;
}
