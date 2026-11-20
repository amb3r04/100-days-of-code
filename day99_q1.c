/**
 * Day 99 - Question 149
 * 
 * Use malloc() to allocate structure memory dynamically and print details.
 * 
 * Test Cases:
 * Test Case 1:
 *   Input: Student allocated dynamically with details: Tina 105 88
 *   Output: Name: Tina | Roll: 105 | Marks: 88
 *   Explanation: Memory for structure is dynamically allocated on heap using malloc().
 */

#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int roll;
    int marks;
};

int main() {
    struct Student *s = (struct Student *)malloc(sizeof(struct Student));
    if (s == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    if (scanf("%49s %d %d", s->name, &s->roll, &s->marks) == 3) {
        printf("Name: %s | Roll: %d | Marks: %d\n", s->name, s->roll, s->marks);
    }
    free(s);
    return 0;
}
