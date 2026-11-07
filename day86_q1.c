/**
 * Day 86 - Question 136
 * 
 * Use enum to represent menu choices (ADD, SUBTRACT, MULTIPLY) and perform operations using switch.
 * 
 * Test Cases:
 * Test Case 1:
 *   Input: ADD 10 20
 *   Output: 30
 *   Explanation: The enum ADD triggers addition of 10 and 20.
 */

#include <stdio.h>
#include <string.h>

enum Operation { ADD = 1, SUBTRACT, MULTIPLY };

int main() {
    char op[20];
    int a, b;
    if (scanf("%19s %d %d", op, &a, &b) == 3) {
        enum Operation choice;
        if (strcmp(op, "ADD") == 0) choice = ADD;
        else if (strcmp(op, "SUBTRACT") == 0) choice = SUBTRACT;
        else choice = MULTIPLY;

        switch (choice) {
            case ADD:      printf("%d\n", a + b); break;
            case SUBTRACT: printf("%d\n", a - b); break;
            case MULTIPLY: printf("%d\n", a * b); break;
        }
    }
    return 0;
}
