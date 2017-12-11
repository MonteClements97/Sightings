#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "observers.h"

observer * create_observer(char observer_ID[5], double latitude, double longitude){
    printf("Inside create observer\n");
    observer * new_observer = malloc(sizeof(observer));
    if(!new_observer){
        printf("ASSIGNING MEMORY FAILED");
        exit(2);
    }
    strcpy(new_observer->observer_ID, observer_ID);
    new_observer->latitude = latitude;
    new_observer->longitude = longitude;
    new_observer->pointer = NULL;
    printf("Created observer success\n");
    return new_observer;
}

observer * insert_observer(observer * head, observer * current_observer, observer * observer_to_insert){
    printf("Inside insert observer\n");
    if(!head){
        printf("returned observer when !head\n");
        return observer_to_insert;
    }
    printf("Past head check is null\n");
    while (current_observer){
        printf("Inside while loop\n");
        if(current_observer->pointer){
            printf("Inside if statement\n");
            current_observer = current_observer->pointer;
            printf("Updated current_observer\n");
            continue;
        }

        current_observer->pointer = observer_to_insert;
        printf("Inserted into linked list\n");
        return head;
    }
    return head;
}

