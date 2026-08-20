/*
Q22: Write a program to find profit or loss percentage given cost price and selling price.

Sample Test Cases:
Input 1:
1000 1200
Output 1:
Profit 20%

Input 2:
1000 800
Output 2:
Loss 20%

Input 3:
1000 1000
Output 3:
No Profit No Loss
*/

#include <stdio.h>

int main() {
    double cp, sp;
    printf("Enter CP and SP: ");
    if (scanf("%lf %lf", &cp, &sp) == 2) {
        if (sp > cp) {
            double profit_pct = ((sp - cp) / cp) * 100.0;
            if (profit_pct == (int)profit_pct)
                printf("Profit %d%%\n", (int)profit_pct);
            else
                printf("Profit %.2f%%\n", profit_pct);
        } else if (cp > sp) {
            double loss_pct = ((cp - sp) / cp) * 100.0;
            if (loss_pct == (int)loss_pct)
                printf("Loss %d%%\n", (int)loss_pct);
            else
                printf("Loss %.2f%%\n", loss_pct);
        } else {
            printf("No Profit No Loss\n");
        }
    }
    return 0;
}
