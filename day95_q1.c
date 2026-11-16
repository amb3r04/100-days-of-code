/**
 * Day 95 - Question 145
 * 
 * Return a structure containing top student's details from a function.
 * 
 * Test Cases:
 * Test Case 1:
 *   Input: 3 students: Riya 101 89, Karan 102 96, Meena 103 92
 *   Output: Top Student: Karan | Roll: 102 | Marks: 96
 *   Explanation: The function returns the structure containing the highest scoring student's details.
 */

#include <stdio.h>

struct Student {
    char name[50];
    int roll;
    int marks;
};

struct Student findTopStudent(struct Student arr[], int n) {
    int maxIdx = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i].marks > arr[maxIdx].marks) {
            maxIdx = i;
        }
    }
    return arr[maxIdx];
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    struct Student students[100];
    for (int i = 0; i < n; i++) {
        scanf("%49s %d %d", students[i].name, &students[i].roll, &students[i].marks);
    }
    struct Student top = findTopStudent(students, n);
    printf("Top Student: %s | Roll: %d | Marks: %d\n", top.name, top.roll, top.marks);
    return 0;
}
