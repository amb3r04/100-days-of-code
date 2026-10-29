/**
 * Day 77 - Question 127
 * 
 * Write a program that reads text from input.txt, converts all lowercase letters to uppercase, and writes the result to output.txt.
 * 
 * Test Cases:
 * Test Case 1:
 *   Input: Input File (input.txt): Hello World\nC programming
 *   Output: Output File (output.txt): HELLO WORLD\nC PROGRAMMING
 *   Explanation: All lowercase letters in input.txt are converted to uppercase using character manipulation before writing to output.txt.
 */

#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *in = fopen("input.txt", "r");
    if (in == NULL) {
        printf("Error: Could not open input.txt\n");
        return 1;
    }
    FILE *out = fopen("output.txt", "w");
    if (out == NULL) {
        printf("Error: Could not create output.txt\n");
        fclose(in);
        return 1;
    }
    int ch;
    while ((ch = fgetc(in)) != EOF) {
        fputc(toupper((unsigned char)ch), out);
    }
    fclose(in);
    fclose(out);
    printf("Successfully converted and written to output.txt\n");
    return 0;
}
