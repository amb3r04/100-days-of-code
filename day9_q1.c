/*
Q17: Write a program to find the roots of a quadratic equation and categorize them.

Sample Test Cases:
Input 1:
1 -3 2
Output 1:
Roots are real and different: 2, 1

Input 2:
1 -2 1
Output 2:
Roots are real and same: 1

Input 3:
1 2 5
Output 3:
Roots are complex
*/

#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    printf("Enter coefficients a, b, c: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) == 3) {
        double d = b * b - 4 * a * c;
        if (d > 0) {
            double r1 = (-b + sqrt(d)) / (2 * a);
            double r2 = (-b - sqrt(d)) / (2 * a);
            if (r1 == (int)r1 && r2 == (int)r2)
                printf("Roots are real and different: %d, %d\n", (int)r1, (int)r2);
            else
                printf("Roots are real and different: %.2f, %.2f\n", r1, r2);
        } else if (d == 0) {
            double r = -b / (2 * a);
            if (r == (int)r)
                printf("Roots are real and same: %d\n", (int)r);
            else
                printf("Roots are real and same: %.2f\n", r);
        } else {
            printf("Roots are complex\n");
        }
    }
    return 0;
}
