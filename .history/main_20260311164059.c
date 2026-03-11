#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Package {
    int package_id;
    char destination[50];
    float price;
    char created_by[50];
};

struct Customer {
    int customer_id;
    char name[50];
    char phone[20];
    char email[50];
    char address[100];
};

struct Booking {
    int booking_id;
    int customer_id;
    int package_id;
    char booking_date[20];
    char travel_date[20];
    int number_of_people;
};

struct Payment {
    int payment_id;
    int booking_id;
    float amount;
    char payment_date[20];
    char payment_method[20];
};

void addPackage() {
    FILE *fp = fopen("packages.txt", "a");
    struct Package p;

    printf("Enter Package ID: ");
    scanf("%d", &p.package_id);

    printf("Enter Destination: ");
    scanf("%s", p.destination);

    printf("Enter Price: ");
    scanf("%f", &p.price);

    printf("Created By: ");
    scanf("%s", p.created_by);

    fprintf(fp, "%d %s %.2f %s\n", p.package_id, p.destination, p.price, p.created_by);

    fclose(fp);
    printf("Package Added Successfully!\n");
}

void viewPackages() {
    FILE *fp = fopen("packages.txt", "r");
    struct Package p;

    printf("\n--- Package List ---\n");

    while (fscanf(fp, "%d %s %f %s", &p.package_id, p.destination, &p.price, p.created_by) != EOF) {
        printf("ID: %d | Destination: %s | Price: %.2f | Created By: %s\n",
               p.package_id, p.destination, p.price, p.created_by);
    }

    fclose(fp);
}

void addCustomer() {
    FILE *fp = fopen("customers.txt", "a");
    struct Customer c;

    printf("Customer ID: ");
    scanf("%d", &c.customer_id);

    printf("Name: ");
    scanf("%s", c.name);

    printf("Phone: ");
    scanf("%s", c.phone);

    printf("Email: ");
    scanf("%s", c.email);

    printf("Address: ");
    scanf("%s", c.address);

    fprintf(fp, "%d %s %s %s %s\n",
            c.customer_id, c.name, c.phone, c.email, c.address);

    fclose(fp);

    printf("Customer Added Successfully!\n");
}

void viewCustomers() {
    FILE *fp = fopen("customers.txt", "r");
    struct Customer c;

    printf("\n--- Customer List ---\n");

    while (fscanf(fp, "%d %s %s %s %s",
                  &c.customer_id, c.name, c.phone, c.email, c.address) != EOF) {

        printf("ID: %d | Name: %s | Phone: %s | Email: %s | Address: %s\n",
               c.customer_id, c.name, c.phone, c.email, c.address);
    }

    fclose(fp);
}

void addBooking() {
    FILE *fp = fopen("bookings.txt", "a");
    struct Booking b;

    printf("Booking ID: ");
    scanf("%d", &b.booking_id);

    printf("Customer ID: ");
    scanf("%d", &b.customer_id);

    printf("Package ID: ");
    scanf("%d", &b.package_id);

    printf("Booking Date: ");
    scanf("%s", b.booking_date);

    printf("Travel Date: ");
    scanf("%s", b.travel_date);

    printf("Number of People: ");
    scanf("%d", &b.number_of_people);

    fprintf(fp, "%d %d %d %s %s %d\n",
            b.booking_id, b.customer_id, b.package_id,
            b.booking_date, b.travel_date, b.number_of_people);

    fclose(fp);

    printf("Booking Added Successfully!\n");
}

void addPayment() {
    FILE *fp = fopen("payments.txt", "a");
    struct Payment p;

    printf("Payment ID: ");
    scanf("%d", &p.payment_id);

    printf("Booking ID: ");
    scanf("%d", &p.booking_id);

    printf("Amount: ");
    scanf("%f", &p.amount);

    printf("Payment Date: ");
    scanf("%s", p.payment_date);

    printf("Payment Method: ");
    scanf("%s", p.payment_method);

    fprintf(fp, "%d %d %.2f %s %s\n",
            p.payment_id, p.booking_id, p.amount,
            p.payment_date, p.payment_method);

    fclose(fp);

    printf("Payment Recorded Successfully!\n");
}

int main() {

    int choice;

    while (1) {

        printf("\n===== Travel Package Management System =====\n");
        printf("1. Add Package\n");
        printf("2. View Packages\n");
        printf("3. Add Customer\n");
        printf("4. View Customers\n");
        printf("5. Add Booking\n");
        printf("6. Add Payment\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            addPackage();
            break;

        case 2:
            viewPackages();
            break;

        case 3:
            addCustomer();
            break;

        case 4:
            viewCustomers();
            break;

        case 5:
            addBooking();
            break;

        case 6:
            addPayment();
            break;

        case 7:
            printf("Exiting Program...\n");
            exit(0);

        default:
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}