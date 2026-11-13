/**
 * Day 92 - Question 142
 * 
 * Store details of 5 students in an array of structures and print all.
 * 
 * Test Cases:
 * Test Case 1:
 *   Input: Details of 5 students (Name, Roll, Marks)
 *   Output: Tabular list of all 5 students with their details
 *   Explanation: The array of structures stores multiple student records and displays them in a table.
 */

#include <stdio.h>

struct Student {
    char name[50];
    int roll;
    int marks;
};

int main() {
    struct Student students[5];
    for (int i = 0; i < 5; i++) {
        if (scanf("%49s %d %d", students[i].name, &students[i].roll, &students[i].marks) != 3) {
            break;
        }
    }
    printf("%-15s %-10s %-10s\n", "Name", "Roll", "Marks");
    printf("-----------------------------------\n");
    for (int i = 0; i < 5; i++) {
        printf("%-15s %-10d %-10d\n", students[i].name, students[i].roll, students[i].marks);
    }
    return 0;
}
