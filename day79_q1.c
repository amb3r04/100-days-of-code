/**
 * Day 79 - Question 129
 * 
 * A file numbers.txt contains a list of integers separated by spaces. Read all integers, compute their sum and average, and print both.
 * 
 * Test Cases:
 * Test Case 1:
 *   Input: File: numbers.txt (Content: 10 20 30 40 50)
 *   Output: Sum = 150
Average = 30.00
 *   Explanation: The program reads integers from the file, computes their total sum (150), and calculates the average (30.00).
 */

#include <stdio.h>

int main() {
    FILE *fp = fopen("numbers.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open numbers.txt\n");
        return 1;
    }
    int num, count = 0;
    long long sum = 0;
    while (fscanf(fp, "%d", &num) == 1) {
        sum += num;
        count++;
    }
    fclose(fp);
    if (count > 0) {
        printf("Sum = %lld\nAverage = %.2f\n", sum, (double)sum / count);
    } else {
        printf("Sum = 0\nAverage = 0.00\n");
    }
    return 0;
}
