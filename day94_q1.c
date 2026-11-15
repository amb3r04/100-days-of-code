/**
 * Day 94 - Question 144
 * 
 * Write a function that accepts a structure as parameter and prints its members.
 * 
 * Test Cases:
 * Test Case 1:
 *   Input: Student: Neha 104 92
 *   Output: Name: Neha | Roll: 104 | Marks: 92
 *   Explanation: The structure is passed by value to a function that prints its data.
 */

#include <stdio.h>

struct Student {
    char name[50];
    int roll;
    int marks;
};

void displayStudent(struct Student s) {
    printf("Name: %s | Roll: %d | Marks: %d\n", s.name, s.roll, s.marks);
}

int main() {
    struct Student s;
    if (scanf("%49s %d %d", s.name, &s.roll, &s.marks) == 3) {
        displayStudent(s);
    }
    return 0;
}
