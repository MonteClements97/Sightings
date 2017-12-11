#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "observers.h"
#include "sightings.h"
#include "conversion_using_math.h"


void find_and_store_locations(observer * observers, sighting * sightings) {
    if (observers && sightings) {
        FILE * location_file = fopen("../locations.txt", "w");
        if(!location_file){
            printf("ERROR OPENING FILE");
            exit(4);
        }
        while(sightings){
            observer *observer_to_work_with = get_observer(observers, sightings);
            if (observer_to_work_with) {
                double observer_latitude_in_radians = observer_to_work_with->latitude * (M_PI / 180.0);
                double mammal_bearing_in_radians = sightings->bearing * (M_PI / 180.0);
                double mammal_latitude = observer_to_work_with->latitude +
                        (sightings->distance * cos(mammal_bearing_in_radians)) / 60.0;
                double mammal_longitude =
                        observer_to_work_with->longitude + ((sightings->distance * sin(mammal_bearing_in_radians)
                                                            / cos(observer_latitude_in_radians)) / 60.0);
                /*if (mammal_latitude < 52.0 || mammal_latitude > 52.833
                    || mammal_longitude > -4.0 || mammal_longitude < -5.50){
                    sighting * temp_pointer_store = sightings->pointer;
                    free(sightings);
                    sightings = temp_pointer_store;
                }*/ //else {
                    fprintf(location_file, "%c %.6lf %.6lf\n",
                            sightings->type_of_mammal, mammal_latitude, mammal_longitude);
                    sighting * temp_pointer_store = sightings->pointer;
                    free(sightings);
                    sightings = temp_pointer_store;
                //}
            }
        }
        if(fclose(location_file) == EOF){
            printf("ERROR CLOSING FILE");
            exit(3);
        }
    }
}

observer * get_observer(observer * observers, sighting * sightings){
    if(!strcmp(observers->observer_ID, sightings->observer_ID)){
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