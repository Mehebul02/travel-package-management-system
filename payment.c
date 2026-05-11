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

void viewPayment() {

    FILE *fp = fopen("payments.txt", "r");

    int pid;
    float amount;

    printf("\n===== Payment List =====\n");

    while (fscanf(fp, "%d %f", &pid, &amount) != EOF) {
        printf("Payment ID: %d | Amount: %.2f\n", pid, amount);
    }

    fclose(fp);
}