#include <stdio.h>
#include <string.h>
#include "auth.h"

int login() {
    FILE *fp = fopen("users.txt", "r");

    char u1[50], p1[50];
    char u2[50], p2[50];

    if (fp == NULL) {
        printf("No user database found!\n");
        return 0;
    }

    printf("Username: ");
    scanf("%s", u1);

    printf("Password: ");
    scanf("%s", p1);

    while (fscanf(fp, "%s %s", u2, p2) != EOF) {
        if (strcmp(u1, u2) == 0 && strcmp(p1, p2) == 0) {
            fclose(fp);
            printf("Login Successful!\n");
            return 1;
        }
    }

    fclose(fp);
    printf("Invalid Login!\n");
    return 0;
}

void registerUser() {
    FILE *fp = fopen("users.txt", "a");

    char u[50], p[50];

    printf("New Username: ");
    scanf("%s", u);

    printf("New Password: ");
    scanf("%s", p);

    fprintf(fp, "%s %s\n", u, p);
    fclose(fp);

    printf("Registration Successful!\n");
}