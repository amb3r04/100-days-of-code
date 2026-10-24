/**
 * Day 72 - Question 122
 * 
 * Write a C program that opens an existing file (e.g., info.txt) and reads its contents using fgets(). The program should print all the lines to the console until EOF (end of file) is reached.
 * 
 * Test Cases:
 * Test Case 1:
 *   Input: File: info.txt (Content: Name: Rahul\nAge: 23)
 *   Output: Name: Rahul
Age: 23
 *   Explanation: The program reads each line from info.txt using fgets() and prints it until EOF.
 */

#include <stdio.h>

int main() {
    FILE *fp = fopen("info.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open info.txt!\n");
        return 1;
    }
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    fclose(fp);
    return 0;
}
