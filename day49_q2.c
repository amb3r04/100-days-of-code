/*
Q98: Print initials of a name with the surname displayed in full.

Sample Test Cases:
Input 1:
John David Doe
Output 1:
J.D. Doe
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char words[20][100];
    int count = 0;
    while (scanf("%s", words[count]) == 1) {
        count++;
        char ch = getchar();
        if (ch == '\n' || ch == EOF) break;
    }
    if (count == 0) return 0;
    for (int i = 0; i < count - 1; i++) {
        printf("%c.", toupper(words[i][0]));
    }
    if (count > 1) printf(" ");
    printf("%s\n", words[count - 1]);
    return 0;
}
