/**
 * Day 75 - Question 125
 * 
 * Open an existing file in append mode and allow the user to enter a new line of text. Append the text at the end without overwriting existing content.
 * 
 * Test Cases:
 * Test Case 1:
 *   Input: Existing File: data.txt (Content before execution: Hello world)
User Input: This is appended text.
 *   Output: File updated successfully with appended text.
 *   Explanation: Output File (data.txt after execution): Hello world\nThis is appended text.
 */

#include <stdio.h>
#include <string.h>

int main() {
    char filename[100];
    char text[500];
    if (scanf("%99s", filename) != 1) return 0;
    getchar();
    if (fgets(text, sizeof(text), stdin)) {
        text[strcspn(text, "\r\n")] = '\0';
        FILE *fp = fopen(filename, "a");
        if (fp == NULL) {
            printf("Error opening file!\n");
            return 1;
        }
        fprintf(fp, "\n%s", text);
        fclose(fp);
        printf("File updated successfully with appended text.\n");
    }
    return 0;
}
