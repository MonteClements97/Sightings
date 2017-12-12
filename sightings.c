#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sightings.h"

sighting * create_sighting(char observer_ID[5], char type_of_mammal, double bearing, double distance){
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
    return new_sighting;
}

sighting * insert_sighting(sighting * head, sighting * sighting_to_insert){
    if(!head){
        return sighting_to_insert;
    }
    sighting_to_insert->pointer = head;
    return sighting_to_insert;
}