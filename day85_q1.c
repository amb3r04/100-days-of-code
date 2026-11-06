/**
 * Day 85 - Question 135
 * 
 * Assign explicit values starting from 10 and print them.
 * 
 * Test Cases:
 * Test Case 1:
 *   Input: No input
 *   Output: A=10
B=11
C=12
 *   Explanation: Enum values can be explicitly assigned; subsequent values auto-increment.
 */

#include <stdio.h>

enum CustomEnum {
    A = 10,
    B,
    C
};

int main() {
    printf("A=%d\n", A);
    printf("B=%d\n", B);
    printf("C=%d\n", C);
    return 0;
}
