/*
Q105: Print the majority element that appears strictly more than floor(n/2) times.
Print -1 if no such element exists.

Sample Test Cases:
Input 1:
nums = [3,2,3]
Output 1:
3

Input 2:
nums = [2,2,1,1,1,2,2]
Output 2:
2

Input 3:
nums = [2,2,1,1,1,2,2,3]
Output 3:
-1
*/

#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) == 1) {
        int arr[1000];
        printf("Enter elements: ");
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        
        // Boyer-Moore Voting Algorithm
        int candidate = arr[0], count = 0;
        for (int i = 0; i < n; i++) {
            if (count == 0) candidate = arr[i];
            count += (arr[i] == candidate) ? 1 : -1;
        }
        
        int actual_count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == candidate) actual_count++;
        }
        if (actual_count > n / 2) printf("%d\n", candidate);
        else printf("-1\n");
    }
    return 0;
}
