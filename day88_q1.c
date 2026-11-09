/**
 * Day 88 - Question 138
 * 
 * Print all enum names and integer values using a loop.
 * 
 * Test Cases:
 * Test Case 1:
 *   Input: No input
 *   Output: RED=0
YELLOW=1
GREEN=2
 *   Explanation: Iterating through enum values prints each constant with its assigned integer.
 */

#include <stdio.h>

enum Color { RED, YELLOW, GREEN, COLOR_COUNT };

int main() {
    const char *names[] = {"RED", "YELLOW", "GREEN"};
    for (int i = 0; i < COLOR_COUNT; i++) {
        printf("%s=%d\n", names[i], i);
    }
    return 0;
}
