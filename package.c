#include <stdio.h>
#include "package.h"

void addPackage() {
    FILE *fp = fopen("packages.txt", "a");
    int id;
    char name[50];
    float price;

    printf("ID: ");
    scanf("%d", &id);

    printf("Destination: ");
    scanf(" %[^\n]", name);

    printf("Price: ");
    scanf("%f", &price);

    fprintf(fp, "%d %s %.2f\n", id, name, price);
    fclose(fp);

    printf("Package Added!\n");
}

void viewPackage() {
    FILE *fp = fopen("packages.txt", "r");
    int id;
    char name[50];
    float price;

    printf("\n--- Packages ---\n");

    while (fscanf(fp, "%d %s %f", &id, name, &price) != EOF) {
        printf("%d | %s | %.2f\n", id, name, price);
    }

    fclose(fp);
}

void searchPackage() {
    FILE *fp = fopen("packages.txt", "r");
    int id, search;
    char name[50];
    float price;

    printf("Search ID: ");
    scanf("%d", &search);

    while (fscanf(fp, "%d %s %f", &id, name, &price) != EOF) {
        if (id == search) {
            printf("Found: %d %s %.2f\n", id, name, price);
        }
    }

    fclose(fp);
}

void deletePackage() {
    FILE *fp = fopen("packages.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    int id, del;
    char name[50];
    float price;

    printf("Delete ID: ");
    scanf("%d", &del);

    while (fscanf(fp, "%d %s %f", &id, name, &price) != EOF) {
        if (id != del) {
            fprintf(temp, "%d %s %.2f\n", id, name, price);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("packages.txt");
    rename("temp.txt", "packages.txt");

    printf("Deleted!\n");
}