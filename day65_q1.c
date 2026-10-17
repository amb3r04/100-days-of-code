/**
 * Day 65 - Question 115
 * 
 * Write a program to take two strings s and t as inputs (assume all characters are lowercase). The task is to determine if s and t are valid anagrams, meaning they contain the same characters with the same frequencies. Print "Anagram" if they are, otherwise "Not Anagram".
 * 
 * Test Cases:
 * Test Case 1:
 *   Input: s = "anagram", t = "nagaram"
 *   Output: Anagram
 *   Explanation: The strings contain the same characters with the same frequencies.
 * Test Case 2:
 *   Input: s = "rat", t = "car"
 *   Output: Not Anagram
 *   Explanation: The strings do not contain the same characters.
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isAnagram(const char *s, const char *t) {
    if (strlen(s) != strlen(t)) return false;
    int count[256] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        count[(unsigned char)s[i]]++;
        count[(unsigned char)t[i]]--;
    }
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) return false;
    }
    return true;
}

int main() {
    char s[500], t[500];
    if (scanf("%499s %499s", s, t) == 2) {
        if (isAnagram(s, t)) {
            printf("Anagram\n");
        } else {
            printf("Not Anagram\n");
        }
    }
    return 0;
}
