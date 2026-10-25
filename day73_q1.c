/**
 * Day 73 - Question 123
 * 
 * Read a text file and count the total number of characters, words, and lines. A word is defined as a sequence of non-space characters separated by spaces or newlines.
 * 
 * Test Cases:
 * Test Case 1:
 *   Input: File: sample.txt (Content: Hello world\nThis is C programming)
 *   Output: Characters: 31
Words: 5
Lines: 2
 *   Explanation: The file has 31 characters including spaces and newlines, 5 words, and 2 lines.
 */

#include <stdio.h>
#include <ctype.h>

int main() {
    char filename[100];
    if (scanf("%99s", filename) != 1) return 0;
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }
    int chars = 0, words = 0, lines = 0;
    int inWord = 0;
    int ch, lastCh = '\n';
    while ((ch = fgetc(fp)) != EOF) {
        chars++;
        if (ch == '\n') lines++;
        if (isspace(ch)) {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            words++;
        }
        lastCh = ch;
    }
    if (chars > 0 && lastCh != '\n') lines++;
    fclose(fp);
    printf("Characters: %d\nWords: %d\nLines: %d\n", chars, words, lines);
    return 0;
}
