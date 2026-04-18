#include <stdio.h>
#include "booking.h"

void addBooking() {
    FILE *fp = fopen("bookings.txt", "a");

    int bid, cid, pid;

    printf("Booking ID: ");
    scanf("%d", &bid);

    printf("Customer ID: ");
    scanf("%d", &cid);

    printf("Package ID: ");
    scanf("%d", &pid);

    fprintf(fp, "%d %d %d\n", bid, cid, pid);
    fclose(fp);

    printf("Booking Added!\n");
}

void viewBooking() {
    FILE *fp = fopen("bookings.txt", "r");

    int bid, cid, pid;

    printf("\n--- Bookings ---\n");

    while (fscanf(fp, "%d %d %d", &bid, &cid, &pid) != EOF) {
        printf("%d | %d | %d\n", bid, cid, pid);
    }

    fclose(fp);
}

void cancelBooking() {
    FILE *fp = fopen("bookings.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    int bid, cid, pid, del;

    printf("Cancel Booking ID: ");
    scanf("%d", &del);

    while (fscanf(fp, "%d %d %d", &bid, &cid, &pid) != EOF) {
        if (bid != del) {
            fprintf(temp, "%d %d %d\n", bid, cid, pid);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("bookings.txt");
    rename("temp.txt", "bookings.txt");

    printf("Cancelled!\n");
}