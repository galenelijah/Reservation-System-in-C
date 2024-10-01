#include <stdio.h>
#include <stdlib.h>

typedef struct Reserve {
    char name[50];
    int people;
    int num;
    char type[50];
    struct Reserve *link;
} res, *list;

void addReserve(list *L);
void display(list L);
void cancelReserve(list *L, int cancel);

int main() {
    list L = NULL;
    int choice = 0;
    int cancel;

    while (choice != 4) {
        printf("\n1. Make Reservation\n2. Cancel Reservation\n3. Display Reservations\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addReserve(&L);
                break;

            case 2:
                printf("Enter Reservation Number to be Cancelled: ");
                scanf("%d", &cancel);
                cancelReserve(&L, cancel);
                break;

            case 3:
                display(L);
                break;

            case 4:
                printf("Thank you!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addReserve(list *L) {
    int i, num;

    printf("How many Reservations: ");
    scanf("%d", &num);

    for (i = 0; i < num; i++) {
        res *RES = malloc(sizeof(res));

        // Set the reservation number
        if (*L == NULL) {
            RES->num = 1;  // If list is empty, start with reservation number 1
        } else {
            RES->num = (*L)->num + 1;  // Otherwise, increment based on the latest reservation
        }

        printf("Enter Name: ");
        scanf("%s", RES->name);
        printf("How many People: ");
        scanf("%d", &RES->people);
        printf("Type of Meal (Breakfast, Lunch, Dinner): ");
        scanf("%s", RES->type);

        // Insert at the beginning of the list
        RES->link = *L;
        *L = RES;
    }
}

void display(list L) {
    if (L == NULL) {
        printf("No reservations found.\n");
        return;
    }

    while (L != NULL) {
        printf("Reservation Number: %d\n", L->num);
        printf("Name: %s\n", L->name);
        printf("Number of People: %d\n", L->people);
        printf("Type: %s\n\n", L->type);
        L = L->link;
    }
}

void cancelReserve(list *L, int cancel) {
    res *temp = *L, *prev = NULL;

    // If head node itself holds the reservation to be canceled
    if (temp != NULL && temp->num == cancel) {
        *L = temp->link;  // Change head
        free(temp);  // Free the memory
        printf("Reservation %d cancelled.\n", cancel);
        return;
    }

    // Search for the reservation to be canceled
    while (temp != NULL && temp->num != cancel) {
        prev = temp;
        temp = temp->link;
    }

    // If reservation was not found
    if (temp == NULL) {
        printf("Reservation number %d not found.\n", cancel);
        return;
    }

    // Unlink the node from the linked list
    prev->link = temp->link;

    free(temp);  // Free the memory
    printf("Reservation %d cancelled.\n", cancel);
}
