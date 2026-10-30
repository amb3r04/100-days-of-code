/**
 * Day 78 - Question 128
 * 
 * Read a text file and count how many vowels and consonants are in the file. Ignore digits and special characters.
 * 
 * Test Cases:
 * Test Case 1:
 *   Input: File: text.txt (Content: Welcome to C language)
 *   Output: Vowels: 8
Consonants: 10
 *   Explanation: The program iterates through each character, counts vowels (A, E, I, O, U) and consonants, ignoring other symbols.
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
    int vowels = 0, consonants = 0;
    int ch;
    while ((ch = fgetc(fp)) != EOF) {
        if (isalpha(ch)) {
            char lower = tolower((unsigned char)ch);
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    fclose(fp);
    printf("Vowels: %d\nConsonants: %d\n", vowels, consonants);
    return 0;
}
