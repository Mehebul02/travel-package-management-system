#include <stdio.h>
#include <stdlib.h>
#include "auth.h"
#include "package.h"
#include "customer.h"
#include "booking.h"
#include "payment.h"

int main()
{

    int choice;

    while (1)
    {

        printf("\n1.Register\n2.Login\n3.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            registerUser();
        }
        else if (choice == 2)
        {

            if (login())
            {

                while (1)
                {

                    printf("\n===== MENU =====\n");
                    printf("1.Add Package\n");
                    printf("2.View Package\n");
                    printf("3.Search Package\n");
                    printf("4.Delete Package\n");

                    printf("5.Add Customer\n");
                    printf("6.View Customer\n");
                    printf("7.Search Customer\n");
                    printf("8.Delete Customer\n");

                    printf("9.Add Booking\n");
                    printf("10.View Booking\n");
                    printf("11.Cancel Booking\n");

                    printf("12.Add Payment\n");
                    printf("13.View Payment\n");
                    printf("14.Exit\n");

                    printf("Enter choice: ");
                    scanf("%d", &choice);

                    switch (choice)
                    {

                    case 1:
                        addPackage();
                        break;

                    case 2:
                        viewPackage();
                        break;

                    case 3:
                        searchPackage();
                        break;

                    case 4:
                        deletePackage();
                        break;

                    case 5:
                        addCustomer();
                        break;

                    case 6:
                        viewCustomer();
                        break;

                    case 7:
                        searchCustomer();
                        break;

                    case 8:
                        deleteCustomer();
                        break;

                    case 9:
                        addBooking();
                        break;

                    case 10:
                        viewBooking();
                        break;

                    case 11:
                        cancelBooking();
                        break;

                    case 12:
                        addPayment();
                        break;
                    case 13:
                        viewPayment();
                        break;

                    case 14:
                        exit(0);

                    default:
                        printf("Invalid Choice!\n");
                    }
                }
            }
        }
        else
        {
            exit(0);
        }
    }

    return 0;
}