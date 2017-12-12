#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "observers.h"
#include "sightings.h"
#include "conversion_using_math.h"
#define M_PI 3.14159265358979323846  /* pi */
#define MAXIMUM_LONGITUDE (-4.0)
#define MINIMUM_LONGITUDE (-5.50)
#define MAXIMUM_LATITUDE (52.833)
#define MINIMUM_LATITUDE (52.0)



void find_and_store_locations(observer * observers, sighting * sightings) {
    if (observers && sightings) {
        char file_name[50];
        printf("Please decide what you wish the file to be called: ");
        scanf(" %s", file_name);
        FILE * location_file = fopen(file_name, "w");
        while(!location_file) {
            printf("ERROR OPENING FILE\n");
            printf("That didn't seem quite right, try again (enter a single q to quit): ");
            scanf(" %s", file_name);
            if (!strcmp(file_name, "q")){
                exit(4);
            } else {
                location_file = fopen(file_name, "w");
            }
        }
        while(sightings){
            observer *observer_to_work_with = get_observer(observers, sightings);
            if (observer_to_work_with) {
                double * location = get_location(observer_to_work_with->latitude, observer_to_work_with->longitude,
                                                 sightings->bearing, sightings->distance);

                if (location[0] < MINIMUM_LATITUDE || location[0] > MAXIMUM_LATITUDE
                    || location[1] > MAXIMUM_LONGITUDE || location[1] < MINIMUM_LONGITUDE){
                    free(location);
                    sighting * temp_pointer_store = sightings->pointer;
                    free(sightings);
                    sightings = temp_pointer_store;
                } else {
                    fprintf(location_file, "%c %.6lf %.6lf\n",
                            sightings->type_of_mammal, location[0], location[1]);
                    free(location);
                    location = 0;
                    sighting * temp_pointer_store = sightings->pointer;
                    free(sightings);
                    sightings = 0;
                    sightings = temp_pointer_store;
                }
            }
        }
        if(fclose(location_file) == EOF){
            printf("ERROR CLOSING FILE");
            exit(3);
        }

    }
}

observer * get_observer(observer * observers, sighting * sightings){
    if(strcmp(observers->observer_ID, sightings->observer_ID)){
        if(observers->pointer){
            return get_observer(observers->pointer, sightings);
        }
        else{
            printf("COULD NOT FIND MATCHING OBSERVER\n");
            return NULL;
        }
    }
    return observers;
}

double * get_location(double observer_latitude, double observer_longitude, double bearing, double distance){
    double * location = malloc(sizeof(double) * 2);
    if(!location){
        printf("ASSIGNING MEMORY FAILED");
        exit(2);
    }
    double mammal_bearing_in_radians = bearing * (M_PI / 180.0);
    double observer_latitude_in_radians = observer_latitude * (M_PI / 180.0);
    location[0] = observer_latitude + (distance * cos(mammal_bearing_in_radians)) / 60.0;
    location[1] = observer_longitude + ((distance * sin(mammal_bearing_in_radians)
                                / cos(observer_latitude_in_radians)) / 60.0);
    return location;
}
