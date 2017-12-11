#include <stdio.h>
#include <stdlib.h>
#include "file_management.h"

int main() {
    char * observer_text_file_name = malloc(sizeof(char));
    char * sighting_text_file_name = malloc(sizeof(char));
    if (!(observer_text_file_name && sighting_text_file_name)){
        printf("MEMORY ASSIGNMENT HAS FAILED"); // Checking if memory has been allocated
        exit(2);
    }
    FILE * observer_text_file = NULL;
    FILE * sighting_text_file = NULL;

    do {
        printf("Just before open file function\n");
        observer_text_file = open_file(1);
        printf("Just after open file function\n");
    } while (!observer_text_file);
    printf("Just before read observer function\n");
    observer * the_observers = read_observer_file(observer_text_file);
    if(fclose(observer_text_file)){
        printf("ERROR CLOSING FILE");
        exit(3);
    }
    do {
        sighting_text_file = open_file(0);
    } while(!sighting_text_file);
    sighting * the_sightings = read_sighting_file(sighting_text_file);
    if(fclose(sighting_text_file)){
        printf("ERROR CLOSING FILE");
        exit(3);
    }





    return 69;
}