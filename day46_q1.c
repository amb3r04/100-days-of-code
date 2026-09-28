/*
Q91: Remove all vowels from a string.

Sample Test Cases:
Input 1:
education
Output 1:
dctn
*/

#include <stdio.h>
#include <ctype.h>

int main() {
    char str[1000];
    if (scanf("%s", str) == 1) {
        for (int i = 0; str[i] != '\0'; i++) {
            char l = tolower(str[i]);
            if (l != 'a' && l != 'e' && l != 'i' && l != 'o' && l != 'u') {
                putchar(str[i]);
            }
        }
        putchar('\n');
    }
    return 0;
}
