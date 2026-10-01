/*
Q97: Print the initials of a name.

Sample Test Cases:
Input 1:
John Doe
Output 1:
J.D.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char line[1000];
    if (fgets(line, sizeof(line), stdin)) {
        int new_word = 1;
        for (int i = 0; line[i] != '\0' && line[i] != '\n'; i++) {
            if (isalpha(line[i])) {
                if (new_word) {
                    printf("%c.", toupper(line[i]));
                    new_word = 0;
                }
            } else if (line[i] == ' ') {
                new_word = 1;
            }
        }
        printf("\n");
    }
    return 0;
}
