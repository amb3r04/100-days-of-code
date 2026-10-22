/**
 * Day 70 - Question 120
 * 
 * Write a program to take a string input. Change it to sentence case.
 * 
 * Test Cases:
 * Test Case 1:
 *   Input: str = I am trying to build logic.
 *   Output: I Am Trying To Build Logic
 * Test Case 2:
 *   Input: str = The classes are supposed to start early.
 *   Output: The Classes Are Supposed To Start Early.
 * Test Case 3:
 *   Input: str = We are going to look at 26 different test cases.
 *   Output: We Are Going To Look At 26 Different Test Cases.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[1000];
    if (fgets(str, sizeof(str), stdin)) {
        str[strcspn(str, "\r\n")] = '\0';
        int newWord = 1;
        for (int i = 0; str[i] != '\0'; i++) {
            if (isspace((unsigned char)str[i])) {
                newWord = 1;
            } else if (newWord) {
                str[i] = toupper((unsigned char)str[i]);
                newWord = 0;
            } else {
                str[i] = tolower((unsigned char)str[i]);
            }
        }
        printf("%s\n", str);
    }
    return 0;
}
