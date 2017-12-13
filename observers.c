#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sightings.h"
#include "observers.h"

//creates a new observer and returns the observer
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
//inserts the new observer at the start of the linked list
observer * insert_observer(observer * head, observer * observer_to_insert){
    if(!head){
        return observer_to_insert;
    }
    observer_to_insert->pointer = head;
    return observer_to_insert;
}

//retrieves observer if both sighting and observer id are the same
observer * get_observer(observer * observers, sighting * sightings) {
    if (strcmp(observers->observer_ID, sightings->observer_ID)) {
        if (observers->pointer) {
            return get_observer(observers->pointer, sightings);
        } else {
            printf("COULD NOT FIND MATCHING OBSERVER\n");
            return NULL;
        }
    }
    return observers;
}
