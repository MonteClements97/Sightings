#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "observers.h"

observer * create_observer(char observer_ID[5], double latitude, double longitude){
    observer * new_observer = malloc(sizeof(observer));
    if(!new_observer){
        printf("ASSIGNING MEMORY FAILED");
        exit(2);
    }
    strcpy(new_observer->observer_ID, observer_ID);
    new_observer->latitude = latitude;
    new_observer->longitude = longitude;
    new_observer->pointer = NULL;
    return new_observer;
}

observer * insert_observer(observer * head, observer * observer_to_insert){
    if(!head){
        return observer_to_insert;
    }
    observer_to_insert->pointer = head;
    return observer_to_insert;
}

