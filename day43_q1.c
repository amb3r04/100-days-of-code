/*
Q85: Reverse a string.

Sample Test Cases:
Input 1:
abcd
Output 1:
dcba
*/

#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    if (scanf("%s", str) == 1) {
        int len = strlen(str);
        for (int i = 0, j = len - 1; i < j; i++, j--) {
            char t = str[i];
            str[i] = str[j];
            str[j] = t;
        }
        printf("%s\n", str);
    }
    return 0;
}
