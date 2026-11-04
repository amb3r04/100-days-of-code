/**
 * Day 83 - Question 133
 * 
 * Create an enum for months and print how many days each month has.
 * 
 * Test Cases:
 * Test Case 1:
 *   Input: FEB
 *   Output: 28 or 29 days
 *   Explanation: February has 28 days in a normal year and 29 in a leap year.
 */

#include <stdio.h>
#include <string.h>

enum Month {
    JAN = 1, FEB, MAR, APR, MAY, JUN,
    JUL, AUG, SEP, OCT, NOV, DEC
};

int main() {
    char mName[10];
    if (scanf("%9s", mName) == 1) {
        if (strcmp(mName, "FEB") == 0) {
            printf("28 or 29 days\n");
        } else if (strcmp(mName, "APR") == 0 || strcmp(mName, "JUN") == 0 ||
                   strcmp(mName, "SEP") == 0 || strcmp(mName, "NOV") == 0) {
            printf("30 days\n");
        } else {
            printf("31 days\n");
        }
    }
    return 0;
}
