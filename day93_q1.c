/**
 * Day 93 - Question 143
 * 
 * Find and print the student with the highest marks.
 * 
 * Test Cases:
 * Test Case 1:
 *   Input: 3 students: Ravi 101 95, Sita 102 85, Aman 103 88
 *   Output: Topper: Ravi (Marks: 95)
 *   Explanation: Program compares marks of all students and prints the one with the highest.
 */

#include <stdio.h>

struct Student {
    char name[50];
    int roll;
    int marks;
};

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    struct Student students[100];
    int maxIdx = 0;
    for (int i = 0; i < n; i++) {
        scanf("%49s %d %d", students[i].name, &students[i].roll, &students[i].marks);
        if (students[i].marks > students[maxIdx].marks) {
            maxIdx = i;
        }
    }
    printf("Topper: %s (Marks: %d)\n", students[maxIdx].name, students[maxIdx].marks);
    return 0;
}
