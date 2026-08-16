/*
Q14: Write a program to input a character and check whether it is a vowel or consonant using if–else.

Sample Test Cases:
Input 1:
a
Output 1:
Vowel

Input 2:
b
Output 2:
Consonant
*/

#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;
    printf("Enter a character: ");
    if (scanf(" %c", &ch) == 1) {
        char lower = tolower(ch);
        if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')
            printf("Vowel\n");
        else if (isalpha(ch))
            printf("Consonant\n");
        else
            printf("Not an alphabet\n");
    }
    return 0;
}
