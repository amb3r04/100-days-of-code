/*
Q86: Check if a string is a palindrome.

Sample Test Cases:
Input 1:
madam
Output 1:
Palindrome

Input 2:
hello
Output 2:
Not palindrome
*/

#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    if (scanf("%s", str) == 1) {
        int len = strlen(str);
        int pal = 1;
        for (int i = 0, j = len - 1; i < j; i++, j--) {
            if (str[i] != str[j]) {
                pal = 0;
                break;
            }
        }
        if (pal) printf("Palindrome\n");
        else printf("Not palindrome\n");
    }
    return 0;
}
