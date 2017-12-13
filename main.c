#include <stdio.h>
#include <stdlib.h>
#include "sightings.h"
#include "observers.h"
#include "file_management.h"
#include "conversion_using_math.h"

int main() {
    FILE * text_file = NULL;
    do {
        //checks to see if the file that is trying to be opened actually exists
        text_file = open_file(1);
    } while (!text_file);
    observer * the_observers = read_observer_file(text_file);
    if(fclose(text_file) == EOF){
        printf("ERROR CLOSING FILE");
        exit(3);
    }
    do {
        //checks to see if the file that is trying to be opened actually exists
        text_file = open_file(0);
    } while(!text_file);
    sighting * the_sightings = read_sighting_file(text_file);
    if(fclose(text_file) == EOF){
        printf("ERROR CLOSING FILE");
        exit(3);
    }
    find_and_store_locations(the_observers, the_sightings);
    return 0;
}