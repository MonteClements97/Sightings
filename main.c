#include <stdio.h>
#include <stdlib.h>
#include "observers.h"
#include "sightings.h"
#include "file_management.h"
#include "conversion_using_math.h"

int main() {
    char * observer_text_file_name = malloc(sizeof(char));
    char * sighting_text_file_name = malloc(sizeof(char));
    if (!(observer_text_file_name && sighting_text_file_name)){
        printf("MEMORY ASSIGNMENT HAS FAILED"); // Checking if memory has been allocated
        exit(2);
    }
    FILE * text_file = NULL;


    do {
        printf("Just before open file function\n");
        text_file = open_file(1);
        printf("Just after open file function\n");
    } while (!text_file);
    printf("Just before read observer function\n");
    observer * the_observers = read_observer_file(text_file);
    if(fclose(text_file)){
        printf("ERROR CLOSING FILE");
        exit(3);
    }
    do {
        text_file = open_file(0);
    } while(!text_file);
    sighting * the_sightings = read_sighting_file(text_file);
    if(fclose(text_file) == EOF){
        printf("ERROR CLOSING FILE");
        exit(3);
    }
    find_and_store_locations(the_observers, the_sightings);






    return 115;
}