#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void displayClientMenu();
void RoomReserve();
void Reservation(char loggedInUsername[]);
void AdminMenu();
void ClientMenu(char loggedInUsername[]);
void showLoginPage();
void loadReservationsFromFile();

// Function to display the client menu
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

void Reservation(char loggedInUsername[]) {
    char choice;
    do {
        system("clear");
        RoomReserve();
        scanf(" %c", &choice);
        switch (choice) {
            case 'a':
                // sched(loggedInUsername); // sched function is not provided in the given code
                break;
            case 'b':
                // displayRoomInformation(); // displayRoomInformation function is not provided
                printf("[a] Back: ");
                scanf(" %c", &choice);
                while (choice != 'a') {
                    printf("Invalid. Try again.\n");
                    printf("[a] Back: ");
                    scanf(" %c", &choice);
                }
                break;
            case 'c':
                int chosenMonth, chosenFromDate;
                printf("Enter the month number (1-12): ");
                scanf("%d", &chosenMonth);
                printf("Enter the date (1-31): ");
                scanf("%d", &chosenFromDate);
                // DisplayRoomAvailability(chosenMonth, chosenFromDate); // DisplayRoomAvailability is not provided
                printf("[a] Back: ");
                scanf(" %c", &choice);
                while (choice != 'a') {
                    printf("Invalid. Try again.\n");
                    printf("[a] Back: ");
                    scanf(" %c", &choice);
                }
                break;
            case 'd':
                return;
            case 'e':
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 'd');
}

// Function to handle the main admin menu
void AdminMenu() {
    // Display_reservation_admin(); // Display_reservation_admin is not provided
}

void ClientMenu(char loggedInUsername[]) {
    char choice;
    do {
        system("clear");
        displayClientMenu();
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                Reservation(loggedInUsername);
                break;
            case 'b':
                // Display_reservation_client(loggedInUsername); // Display_reservation_client is not provided
                break;
            case 'c':
                // Account_setting(loggedInUsername); // Account_setting function is not provided
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

        // Clear the input buffer to avoid invalid inputs causing issues in the next loop iteration
        while (getchar() != '\n');
    } while (choice != 'd');
}

// Function to login
void showLoginPage() {
    char choice;
    printf("Login System\n");
    printf("[a] Register\n");
    printf("[b] Login\n");
    printf("[c] Exit\n");
    printf("Enter your choice: ");

    scanf(" %c", &choice);
    while (choice != 'a' && choice != 'b' && choice != 'c') {
        printf("Invalid choice. Please try again: ");
        scanf(" %c", &choice);
    }

    switch (choice) {
        case 'a':
            // registerUser(); // registerUser function is not provided
            break;
        case 'b': {
            char loggedInUsername[50];
            printf("Enter username: ");
            scanf("%s", loggedInUsername);
            if (strcmp(loggedInUsername, "admin") == 0) {
                printf("Admin is logged in.\n");
                AdminMenu();
            } else {
                printf("Logged in successfully.\n");
                ClientMenu(loggedInUsername);
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
    system("pause");
}

int main() {
    loadReservationsFromFile();
    while (1) {
        showLoginPage();
    }
    return 0;
}
