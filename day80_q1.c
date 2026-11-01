/**
 * Day 80 - Question 130
 * 
 * Store multiple student records (name, roll number, marks) into a file using fprintf(). Then read them using fscanf() and display each record.
 * 
 * Test Cases:
 * Test Case 1:
 *   Input: Student 1 → Name: Asha, Roll: 101, Marks: 85; Student 2 → Name: Ravi, Roll: 102, Marks: 92
 *   Output: Name: Asha | Roll: 101 | Marks: 85
Name: Ravi | Roll: 102 | Marks: 92
 *   Explanation: Expected File Content (students.txt): Asha 101 85\nRavi 102 92
 */

#include <stdio.h>

struct Student {
    char name[50];
    int roll;
    int marks;
};

int main() {
    int n;
    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    struct Student s[50];
    for (int i = 0; i < n; i++) {
        scanf("%49s %d %d", s[i].name, &s[i].roll, &s[i].marks);
    }
    FILE *fp = fopen("students.txt", "w");
    if (fp == NULL) return 1;
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%s %d %d\n", s[i].name, s[i].roll, s[i].marks);
    }
    fclose(fp);

    fp = fopen("students.txt", "r");
    if (fp == NULL) return 1;
    struct Student readS;
    while (fscanf(fp, "%49s %d %d", readS.name, &readS.roll, &readS.marks) == 3) {
        printf("Name: %s | Roll: %d | Marks: %d\n", readS.name, readS.roll, readS.marks);
    }
    fclose(fp);
    return 0;
}
