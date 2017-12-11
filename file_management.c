#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "observers.h"
#include "sightings.h"
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

observer * read_observer_file(FILE * observer_file){
    printf("Inside read observer function\n");
    observer * head = malloc(sizeof(observer));
    head = NULL;
    char observer_ID[5];
    double latitude;
    double longitude;
    fscanf(observer_file, "%*[^\n]\n");
    printf("After fcansf inside function\n");
    int debug_counter = 0;
    while(fscanf(observer_file, "%s %lf %lf", observer_ID, &latitude, &longitude) != EOF){
        printf("Just before insert observer %d\n", debug_counter);
        observer * new_observer = create_observer(observer_ID, latitude, longitude);
        head = insert_observer(head, head, new_observer);
        debug_counter++;

    }
    return head;
}

sighting * read_sighting_file(FILE * sighting_file){
    printf("Inside read sighting function\n");
    sighting * head = malloc(sizeof(sighting));
    head = NULL;
    char observer_ID[5];
    char type_of_mammal;
    double bearing;
    double distance;
    int debug_counter = 0;
    while(fscanf(sighting_file, "%s %c %lf %lf", observer_ID, &type_of_mammal, &bearing, &distance) != EOF){
        printf("Just before insert sighting %d\n", debug_counter);
        sighting * new_sighting = create_sighting(observer_ID, type_of_mammal, bearing, distance);
        head = insert_sighting(head, head, new_sighting);
        debug_counter++;

    }
    return head;
}

