#include <stdio.h>

void addPayment() {
    FILE *fp = fopen("payments.txt", "a");

    int pid;
    float amount;

    printf("Payment ID: ");
    scanf("%d", &pid);

    printf("Amount: ");
    scanf("%f", &amount);

    fprintf(fp, "%d %.2f\n", pid, amount);

    fclose(fp);

    printf("Payment Done!\n");
}