/**
 * Day 87 - Question 137
 * 
 * Create an enum for user roles (ADMIN, USER, GUEST) and display messages based on role.
 * 
 * Test Cases:
 * Test Case 1:
 *   Input: GUEST
 *   Output: Welcome Guest!
 *   Explanation: Enum value determines which message is displayed.
 */

#include <stdio.h>
#include <string.h>

enum Role { ADMIN, USER, GUEST };

int main() {
    char roleStr[20];
    if (scanf("%19s", roleStr) == 1) {
        enum Role r;
        if (strcmp(roleStr, "ADMIN") == 0) r = ADMIN;
        else if (strcmp(roleStr, "USER") == 0) r = USER;
        else r = GUEST;

        switch (r) {
            case ADMIN: printf("Welcome Admin!\n"); break;
            case USER:  printf("Welcome User!\n"); break;
            case GUEST: printf("Welcome Guest!\n"); break;
        }
    }
    return 0;
}
