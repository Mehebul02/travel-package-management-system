#include <stdio.h>
#include "customer.h"

void addCustomer() {
    FILE *fp = fopen("customers.txt", "a");

    int id;
    char name[50];

    printf("ID: ");
    scanf("%d", &id);

    printf("Name: ");
    scanf(" %[^\n]", name);

    fprintf(fp, "%d %s\n", id, name);
    fclose(fp);

    printf("Customer Added!\n");
}

void viewCustomer() {
    FILE *fp = fopen("customers.txt", "r");

    int id;
    char name[50];

    printf("\n--- Customers ---\n");

    while (fscanf(fp, "%d %s", &id, name) != EOF) {
        printf("%d | %s\n", id, name);
    }

    fclose(fp);
}

void searchCustomer() {
    FILE *fp = fopen("customers.txt", "r");

    int id, search;
    char name[50];

    printf("Search ID: ");
    scanf("%d", &search);

    while (fscanf(fp, "%d %s", &id, name) != EOF) {
        if (id == search) {
            printf("Found: %d %s\n", id, name);
        }
    }

    fclose(fp);
}

void deleteCustomer() {
    FILE *fp = fopen("customers.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    int id, del;
    char name[50];

    printf("Delete ID: ");
    scanf("%d", &del);

    while (fscanf(fp, "%d %s", &id, name) != EOF) {
        if (id != del) {
            fprintf(temp, "%d %s\n", id, name);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("customers.txt");
    rename("temp.txt", "customers.txt");

    printf("Deleted!\n");
}