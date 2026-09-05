/*
Q54: Write a program to print the pyramid star pattern.
*/

#include <stdio.h>

int main() {
    int rows = 4;
    for (int i = 1; i <= rows; i++) {
        for (int s = 1; s <= rows - i; s++) printf(" ");
        for (int j = 1; j <= 2 * i - 1; j++) printf("*");
        printf("\n");
    }
    for (int i = rows - 1; i >= 1; i--) {
        for (int s = 1; s <= rows - i; s++) printf(" ");
        for (int j = 1; j <= 2 * i - 1; j++) printf("*");
        printf("\n");
    }
    return 0;
}
