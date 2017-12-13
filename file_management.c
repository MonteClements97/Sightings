#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sightings.h"
#include "observers.h"
#include "file_management.h"


FILE * open_file (char observer_or_sighting){
    char file_name[50];
    char type_of_file[9];
    if (observer_or_sighting){
        strcpy(type_of_file, "observer");
    } else{
        strcpy(type_of_file, "sighting");
    }

    FILE * text_file = NULL;

    do {
        printf("Please enter the name of the %s text file: ", type_of_file);
        scanf(" %s", file_name);
        text_file = fopen(file_name, "r");
        if (text_file) {
            printf("%s text file success\n", type_of_file);
            return text_file;
        }
        else {
            printf("%s text file fail\n", type_of_file);
            continue;
        }
    } while (!text_file);
    return NULL;
}
//retrieves the observer id, latitude and longitude from a file given from main
//creates a linked list based on all the data read from the file
observer * read_observer_file(FILE * observer_file){
    observer * head = malloc(sizeof(observer));
    if(!head){
        printf("ASSIGNING MEMORY FAILED");
        exit(2);
    }
    head = NULL;
    char observer_ID[5];
    double latitude;
    double longitude;
    fscanf(observer_file, "%*[^\n]\n");
    while(fscanf(observer_file, "%s %lf %lf", observer_ID, &latitude, &longitude) != EOF){
        observer * new_observer = create_observer(observer_ID, latitude, longitude);
        head = insert_observer(head, new_observer); //inserts the newly created observer to the front of the list

    }
    return head;
}
//retrieves the observer id, type of mammal, bearing and distance from a file given from main
//creates a linked list based on all the data read from the file
sighting * read_sighting_file(FILE * sighting_file){
    sighting * head = malloc(sizeof(sighting));
    if(!head){
        printf("ASSIGNING MEMORY FAILED");
        exit(2);
    }
    head = NULL;
    char observer_ID[5];
    char type_of_mammal;
    double bearing;
    double distance;
    while(fscanf(sighting_file, "%s %c %lf %lf", observer_ID, &type_of_mammal, &bearing, &distance) != EOF){
        sighting * new_sighting = create_sighting(observer_ID, type_of_mammal, bearing, distance);
        head = insert_sighting(head, new_sighting); //inserts the newly created sighting to the front of the list

    }
    return head;
}

