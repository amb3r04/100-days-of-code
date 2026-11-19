/**
 * Day 98 - Question 148
 * 
 * Take two structs as input and check if they are identical.
 * 
 * Test Cases:
 * Test Case 1:
 *   Input: Student1: Asha 101 90
Student2: Asha 101 90
 *   Output: Same
 *   Explanation: Compares all structure members and prints 'Same' if identical.
 */

#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int roll;
    int marks;
};

int areIdentical(struct Student s1, struct Student s2) {
    return (strcmp(s1.name, s2.name) == 0 && s1.roll == s2.roll && s1.marks == s2.marks);
}

int main() {
    struct Student s1, s2;
    if (scanf("%49s %d %d", s1.name, &s1.roll, &s1.marks) == 3 &&
        scanf("%49s %d %d", s2.name, &s2.roll, &s2.marks) == 3) {
        if (areIdentical(s1, s2)) {
            printf("Same\n");
        } else {
            printf("Not Same\n");
        }
    }
    return 0;
}
