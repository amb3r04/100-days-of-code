/*
Q94: Find the longest word in a sentence.

Sample Test Cases:
Input 1:
I love programming
Output 1:
programming
*/

#include <stdio.h>
#include <string.h>

int main() {
    char line[1000];
    if (fgets(line, sizeof(line), stdin)) {
        char longest[200] = "";
        char word[200] = "";
        int wlen = 0;
        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] != ' ' && line[i] != '\n' && line[i] != '\t') {
                word[wlen++] = line[i];
            } else {
                word[wlen] = '\0';
                if (wlen > strlen(longest)) {
                    strcpy(longest, word);
                }
                wlen = 0;
            }
        }
        word[wlen] = '\0';
        if (wlen > strlen(longest)) strcpy(longest, word);
        printf("%s\n", longest);
    }
    return 0;
}
