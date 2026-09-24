/*
Q83: Count vowels and consonants in a string.

Sample Test Cases:
Input 1:
hello
Output 1:
Vowels=2, Consonants=3
*/

#include <stdio.h>
#include <ctype.h>

int main() {
    char str[1000];
    if (fgets(str, sizeof(str), stdin)) {
        int v = 0, c = 0;
        for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
            if (isalpha(str[i])) {
                char lower = tolower(str[i]);
                if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')
                    v++;
                else
                    c++;
            }
        }
        printf("Vowels=%d, Consonants=%d\n", v, c);
    }
    return 0;
}
