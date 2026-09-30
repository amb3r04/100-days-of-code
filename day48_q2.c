/*
Q96: Reverse each word in a sentence without changing the word order.

Sample Test Cases:
Input 1:
I love coding
Output 1:
I evol gnidoc
*/

#include <stdio.h>
#include <string.h>

void rev_word(char *start, char *end) {
    while (start < end) {
        char t = *start;
        *start = *end;
        *end = t;
        start++;
        end--;
    }
}

int main() {
    char line[1000];
    if (fgets(line, sizeof(line), stdin)) {
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') line[--len] = '\0';
        char *word_start = line;
        for (int i = 0; i <= len; i++) {
            if (line[i] == ' ' || line[i] == '\0') {
                if (i > (word_start - line)) {
                    rev_word(word_start, &line[i - 1]);
                }
                word_start = &line[i + 1];
            }
        }
        printf("%s\n", line);
    }
    return 0;
}
