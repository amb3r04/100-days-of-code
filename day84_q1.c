/**
 * Day 84 - Question 134
 * 
 * Define an enum with SUCCESS, FAILURE, and TIMEOUT, and print messages accordingly.
 * 
 * Test Cases:
 * Test Case 1:
 *   Input: FAILURE
 *   Output: Operation failed
 *   Explanation: FAILURE corresponds to a failed operation message.
 */

#include <stdio.h>
#include <string.h>

enum Status { SUCCESS, FAILURE, TIMEOUT };

int main() {
    char input[20];
    if (scanf("%19s", input) == 1) {
        enum Status s;
        if (strcmp(input, "SUCCESS") == 0) s = SUCCESS;
        else if (strcmp(input, "FAILURE") == 0) s = FAILURE;
        else s = TIMEOUT;

        switch (s) {
            case SUCCESS: printf("Operation successful\n"); break;
            case FAILURE: printf("Operation failed\n"); break;
            case TIMEOUT: printf("Operation timed out\n"); break;
        }
    }
    return 0;
}
