#include <stdio.h>
#include <stdlib.h>

typedef struct Reserve{
    char name[50];
    int people;
    int num;
    char type[50];
    struct Reserve *link;
} res, *list;

void addReserve(list *L);
void display(list L);
void cancelReserve(list L, int cancel);

int main(){
    list L = NULL;
    res *RES;
    int i, choice;
    int cancel;
    
    while (choice != 4){
        
        printf("1. Make Reservation\n2. Cancel Reservation\n3. Display Reservation\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice){

            case 1:
            addReserve(&L);
            break;

            case 2:
            printf("Enter Reservation Number to be Cancelled:");
            scanf("%d", &cancel);
            cancelReserve(L, cancel);
            break;

            case 3:
            display(L);
            break;

            case 4:
            printf("Thankyou<3");
            break;
        }
    }
    return 0;
}

void addReserve(list *L){
    int i, *j, num;
    j = L->num; 

    printf("How many Reservations:");
    scanf("%d", &num);

    for (i = 0; i < num; i++){
    res *RES = malloc(sizeof(res));
    RES->num = *j + 1;
    printf("Enter Name:");
    scanf("%s", &RES->name);
    printf("How many People:");
    scanf("%d", &RES->people);
    printf("Type of Meal: Breakfast Lunch Dinner\n");
    scanf("%s", &RES->type);
    RES->link = *L;
    *L = RES;
    }
}

void display(list L){

    while (L != NULL){
        printf("Reservation Number: %d\n", L->num);
        printf("Name: %s\n", L->name);
        printf("Number of People: %d\n", L->people);
        printf("Type: %s\n", L->type);
        L = L->link;
    }
}

void cancelReserve(list L, int cancel){
    int i;
    res *temp;
    temp = L;

    for (i = 0; i < cancel; i++){
        if (L->num == cancel){
            L = L->link;
            free(temp);
        }
    }
}