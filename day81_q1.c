/**
 * Day 81 - Question 131
 * 
 * Create an enumeration for days (SUNDAY to SATURDAY) and print each day with its integer value.
 * 
 * Test Cases:
 * Test Case 1:
 *   Input: No input
 *   Output: SUNDAY = 0
MONDAY = 1
TUESDAY = 2
WEDNESDAY = 3
THURSDAY = 4
FRIDAY = 5
SATURDAY = 6
 *   Explanation: Each day in the enum is automatically assigned an integer starting from 0.
 */

#include <stdio.h>

enum Day {
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

int main() {
    const char *names[] = {
        "SUNDAY", "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY"
    };
    for (int d = SUNDAY; d <= SATURDAY; d++) {
        printf("%s = %d\n", names[d], d);
    }
    return 0;
}
