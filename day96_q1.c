/**
 * Day 96 - Question 146
 * 
 * Create Employee structure with nested Date structure for joining date and print details.
 * 
 * Test Cases:
 * Test Case 1:
 *   Input: Employee: Raj | ID: 11 | Joining Date: 12 05 2020
 *   Output: Name: Raj | ID: 11 | Joining Date: 12/05/2020
 *   Explanation: Nested structure Date is used inside Employee structure to represent joining date.
 */

#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Employee {
    char name[50];
    int id;
    struct Date joiningDate;
};

int main() {
    struct Employee emp;
    if (scanf("%49s %d %d %d %d", emp.name, &emp.id,
              &emp.joiningDate.day, &emp.joiningDate.month, &emp.joiningDate.year) == 5) {
        printf("Name: %s | ID: %d | Joining Date: %02d/%02d/%04d\n",
               emp.name, emp.id, emp.joiningDate.day, emp.joiningDate.month, emp.joiningDate.year);
    }
    return 0;
}
