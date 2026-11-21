/**
 * Day 100 - Question 150
 * 
 * Use pointer to struct to modify and display data using -> operator.
 * 
 * Test Cases:
 * Test Case 1:
 *   Input: Student pointer modifying values: John 106 91
 *   Output: Modified Data: Name: John | Roll: 106 | Marks: 91
 *   Explanation: Pointer to structure accesses and modifies data using the arrow (->) operator.
 */

#include <stdio.h>

struct Student {
    char name[50];
    int roll;
    int marks;
};

void modifyStudent(struct Student *ptr, int bonusMarks) {
    ptr->marks += bonusMarks;
}

int main() {
    struct Student s;
    int bonus;
    if (scanf("%49s %d %d %d", s.name, &s.roll, &s.marks, &bonus) == 4) {
        modifyStudent(&s, bonus);
        printf("Modified Data: Name: %s | Roll: %d | Marks: %d\n", s.name, s.roll, s.marks);
    }
    return 0;
}
