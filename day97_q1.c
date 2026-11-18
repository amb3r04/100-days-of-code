/**
 * Day 97 - Question 147
 * 
 * Store employee data in a binary file using fwrite() and read using fread().
 * 
 * Test Cases:
 * Test Case 1:
 *   Input: Employee details entered and stored in file.
 *   Output: Displays employee data read from file.
 *   Explanation: Demonstrates writing and reading structures using binary file handling functions.
 */

#include <stdio.h>

struct Employee {
    char name[50];
    int id;
    float salary;
};

int main() {
    struct Employee empWrite;
    if (scanf("%49s %d %f", empWrite.name, &empWrite.id, &empWrite.salary) == 3) {
        FILE *fp = fopen("employee.bin", "wb");
        if (fp == NULL) return 1;
        fwrite(&empWrite, sizeof(struct Employee), 1, fp);
        fclose(fp);

        struct Employee empRead;
        fp = fopen("employee.bin", "rb");
        if (fp == NULL) return 1;
        fread(&empRead, sizeof(struct Employee), 1, fp);
        fclose(fp);

        printf("Name: %s | ID: %d | Salary: %.2f\n", empRead.name, empRead.id, empRead.salary);
    }
    return 0;
}
