#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Account.h"
#include "HRS.h"
#include "Account_setting.h"
#include "Sorted_roomprice.h"
#include "ReservationSystem.h"

void displayClientMenu();
void RoomReserve();
void Reservation(HotelReservationSystem* sys, const char* loggedInUsername);
void AdminMenu(HotelReservationSystem* sys);
void ClientMenu(HotelReservationSystem* sys, const char* loggedInUsername);
void showLoginPage(HotelReservationSystem* sys);

void displayClientMenu() {
    printf("=== Client Menu ===\n");
    printf("[a] Room Reservation\n");
    printf("[b] Display reservation/s\n");
    printf("[c] Account settings\n");
    printf("[d] Log Out\n");
    printf("[e] Exit\n");
    printf("Enter your choice: ");
}

void RoomReserve() {
    printf("=== Room Reservation ===\n");
    printf("[a] Schedule Room Reservation\n");
    printf("[b] View room types and amenities\n");
    printf("[c] Show available rooms\n");
    printf("[d] Back\n");
    printf("[e] Exit\n");
    printf("Enter your choice: ");
}

void Reservation(HotelReservationSystem* sys, const char* loggedInUsername) {
    char choice;
    do {
        system("cls"); // Note: This might need to be adapted for a non-Windows environment
        RoomReserve();
        scanf(" %c", &choice);
        switch (choice) {
            // Implement sched(loggedInUsername) and other cases accordingly
            // ...

            case 'd':
                return;
            case 'e':
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 'd');
}

void AdminMenu(HotelReservationSystem* sys) {
    // Implement Display_reservation_admin() and other admin functionalities
    // ...
}

void ClientMenu(HotelReservationSystem* sys, const char* loggedInUsername) {
    char choice;
    do {
        system("cls"); // Note: This might need to be adapted for a non-Windows environment
        displayClientMenu();
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                Reservation(sys, loggedInUsername);
                break;
            case 'b':
                // Implement Display_reservation_client(loggedInUsername)
                // ...
                break;
            case 'c':
                // Implement Account_setting(sys, loggedInUsername)
                // ...
                break;
            case 'd':
                printf("Logging out...\n");
                break;
            case 'e':
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

        // Clear the input buffer
        while (getchar() != '\n');

    } while (choice != 'd');
}

void showLoginPage(HotelReservationSystem* sys) {
    Account account;
    system("cls"); // Note: This might need to be adapted for a non-Windows environment
    printf("Login System\n");
    char choice;
    printf("[a] Register\n");
    printf("[b] Login\n");
    printf("[c] Exit\n");
    printf("Enter your choice: ");

    scanf(" %c", &choice);
    while (choice != 'a' && choice != 'b' && choice != 'c') {
        printf("Invalid choice. Please try again: ");
        while (getchar() != '\n');
        scanf(" %c", &choice);
    }

    switch (choice) {
        case 'a':
            account.registerUser();
            break;
        case 'b': {
            char loggedInUsername[100]; // Adjust the size accordingly
            account.loginUser(loggedInUsername);
            if (strlen(loggedInUsername) > 0) {
                if (strcmp(loggedInUsername, "admin") == 0) {
                    printf("Admin is logged in.\n");
                    AdminMenu(sys);
                } else {
                    printf("Logged in successfully.\n");
                    ClientMenu(sys, loggedInUsername);
                }
            }
            break;
        }
        case 'c':
            printf("Exiting...\n");
            exit(0);
        default:
            printf("\nInvalid Input\n");
            break;
    }

    // Clear the input buffer
    while (getchar() != '\n');
    system("pause"); // Note: This might need to be adapted for a non-Windows environment
}

int main() {
    HotelReservationSystem sys;
    // Implement loadReservationsFromFile()
    while (1) {
        showLoginPage(&sys);
    }
    while (getchar() != '\n');
    return 0;
}
