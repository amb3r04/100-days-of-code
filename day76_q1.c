/**
 * Day 76 - Question 126
 * 
 * Ask the user for a filename. Check if it exists by trying to open it in read mode. If the file pointer is NULL, print an error message; otherwise, read and display its content.
 * 
 * Test Cases:
 * Test Case 1:
 *   Input: Filename: sample.txt (File Exists: Yes)
 *   Output: File opened successfully.
(Displays file content)
 *   Explanation: The program opens the existing file and prints its content using fgets().
 * Test Case 2:
 *   Input: Filename: nofile.txt (File Exists: No)
 *   Output: Error: File does not exist!
 *   Explanation: Since fopen() returns NULL, an error message is displayed instead of reading.
 */

#include <stdio.h>

int main() {
    char filename[100];
    if (scanf("%99s", filename) != 1) return 0;
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File does not exist!\n");
    } else {
        printf("File opened successfully.\n");
        char buffer[256];
        while (fgets(buffer, sizeof(buffer), fp) != NULL) {
            printf("%s", buffer);
        }
        fclose(fp);
    }
    return 0;
}
