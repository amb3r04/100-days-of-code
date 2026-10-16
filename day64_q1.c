/**
 * Day 64 - Question 114
 * 
 * Write a program to take a string s as input. The task is to find the length of the longest substring without repeating characters. Print the length as output.
 * 
 * Test Cases:
 * Test Case 1:
 *   Input: s = "abcabcbb"
 *   Output: 3
 *   Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
 * Test Case 2:
 *   Input: s = "bbbbb"
 *   Output: 1
 *   Explanation: The answer is "b", with the length of 1.
 * Test Case 3:
 *   Input: s = "pwwkew"
 *   Output: 3
 *   Explanation: The answer is "wke", with the length of 3. Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(const char *s) {
    int lastPos[256];
    for (int i = 0; i < 256; i++) lastPos[i] = -1;
    
    int maxLen = 0, start = 0;
    int n = strlen(s);
    
    for (int i = 0; i < n; i++) {
        unsigned char ch = (unsigned char)s[i];
        if (lastPos[ch] >= start) {
            start = lastPos[ch] + 1;
        }
        lastPos[ch] = i;
        int curLen = i - start + 1;
        if (curLen > maxLen) {
            maxLen = curLen;
        }
    }
    return maxLen;
}

int main() {
    char s[1000];
    if (fgets(s, sizeof(s), stdin)) {
        s[strcspn(s, "\r\n")] = '\0';
        char *p = s;
        char *q1 = strchr(p, '"');
        if (q1) {
            p = q1 + 1;
            char *q2 = strrchr(p, '"');
            if (q2) *q2 = '\0';
        }
        printf("%d\n", lengthOfLongestSubstring(p));
    }
    return 0;
}
