#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sightings.h"

sighting * create_sighting(char observer_ID[5], char type_of_mammal, double bearing, double distance){
    printf("Inside create sighting\n");
    sighting * new_sighting = malloc(sizeof(sighting));
    if(!new_sighting){
        printf("ASSIGNING MEMORY FAILED");
        exit(2);
    }
    strcpy(new_sighting->observer_ID, observer_ID);
    new_sighting->type_of_mammal = type_of_mammal;
    new_sighting->bearing = bearing;
    new_sighting->distance = distance;
    new_sighting->pointer = NULL;
    printf("Created sighting success\n");
    return new_sighting;
}

sighting * insert_sighting(sighting * head, sighting * current_sighting, sighting * sighting_to_insert){
    printf("Inside insert sighting\n");
    if(!head){
        printf("returned sighting when !head\n");
        return sighting_to_insert;
    }
    printf("Past head check is null\n");
    while (current_sighting){
        printf("Inside while loop\n");
        if(current_sighting->pointer){
            printf("Inside if statement\n");
            current_sighting = current_sighting->pointer;
            printf("Updated current_sighting\n");
            continue;
        }

        current_sighting->pointer = sighting_to_insert;
        printf("Inserted into linked list\n");
        return head;
    }
    return head;
}