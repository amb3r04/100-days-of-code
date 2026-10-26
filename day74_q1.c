/**
 * Day 74 - Question 124
 * 
 * Take two filenames from the user – a source file and a destination file. Copy all the content from the source file to the destination file using fgetc() and fputc().
 * 
 * Test Cases:
 * Test Case 1:
 *   Input: Source File: source.txt (Content: Learning C File Handling)
 *   Output: File copied successfully to destination.txt
 *   Explanation: Expected File (destination.txt): Learning C File Handling
 */

#include <stdio.h>

int main() {
    char src[100], dst[100];
    if (scanf("%99s %99s", src, dst) != 2) return 0;
    FILE *fsrc = fopen(src, "r");
    if (fsrc == NULL) {
        printf("Error: Source file does not exist!\n");
        return 1;
    }
    FILE *fdst = fopen(dst, "w");
    if (fdst == NULL) {
        printf("Error: Destination file could not be created!\n");
        fclose(fsrc);
        return 1;
    }
    int ch;
    while ((ch = fgetc(fsrc)) != EOF) {
        fputc(ch, fdst);
    }
    fclose(fsrc);
    fclose(fdst);
    printf("File copied successfully to %s\n", dst);
    return 0;
}
