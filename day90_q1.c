/**
 * Day 90 - Question 140
 * 
 * Define a struct with enum Gender and print person's gender.
 * 
 * Test Cases:
 * Test Case 1:
 *   Input: Gender=MALE
 *   Output: Male
 *   Explanation: The enum inside the struct allows representing gender as a named constant.
 */

#include <stdio.h>
#include <string.h>

enum Gender { MALE, FEMALE, OTHER };

struct Person {
    char name[50];
    enum Gender gender;
};

int main() {
    char gStr[20];
    if (scanf("%19s", gStr) == 1) {
        struct Person p;
        if (strstr(gStr, "MALE") || strstr(gStr, "Male")) {
            p.gender = MALE;
        } else if (strstr(gStr, "FEMALE") || strstr(gStr, "Female")) {
            p.gender = FEMALE;
        } else {
            p.gender = OTHER;
        }

        switch (p.gender) {
            case MALE:   printf("Male\n"); break;
            case FEMALE: printf("Female\n"); break;
            case OTHER:  printf("Other\n"); break;
        }
    }
    return 0;
}
