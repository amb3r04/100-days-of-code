/**
 * Day 89 - Question 139
 * 
 * Show that enums store integers by printing assigned values.
 * 
 * Test Cases:
 * Test Case 1:
 *   Input: No input
 *   Output: SUCCESS=0, FAILURE=1, TIMEOUT=2
 *   Explanation: Enum constants are internally stored as integer values starting from 0.
 */

#include <stdio.h>

enum Code { SUCCESS = 0, FAILURE = 1, TIMEOUT = 2 };

int main() {
    printf("SUCCESS=%d, FAILURE=%d, TIMEOUT=%d\n", SUCCESS, FAILURE, TIMEOUT);
    return 0;
}
