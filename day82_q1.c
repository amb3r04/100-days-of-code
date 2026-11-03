/**
 * Day 82 - Question 132
 * 
 * Define an enum for traffic lights (RED, YELLOW, GREEN) and print 'Stop', 'Wait', or 'Go' based on its value.
 * 
 * Test Cases:
 * Test Case 1:
 *   Input: GREEN
 *   Output: Go
 *   Explanation: When the enum value is GREEN, the program prints 'Go'.
 */

#include <stdio.h>
#include <string.h>

enum TrafficLight { RED, YELLOW, GREEN };

int main() {
    char input[20];
    if (scanf("%19s", input) == 1) {
        enum TrafficLight light;
        if (strcmp(input, "RED") == 0) light = RED;
        else if (strcmp(input, "YELLOW") == 0) light = YELLOW;
        else light = GREEN;

        switch (light) {
            case RED:    printf("Stop\n"); break;
            case YELLOW: printf("Wait\n"); break;
            case GREEN:  printf("Go\n"); break;
        }
    }
    return 0;
}
