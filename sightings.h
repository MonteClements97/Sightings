
#ifndef SIGHTINGS_SIGHTING_H
#define SIGHTINGS_SIGHTING_H

typedef struct s_sighting {
    char observer_ID[5];
    char type_of_mammal;
    double angle;
    double distance;
    struct s_sighting * pointer;

} sighting;

sighting * create_sighting(char observer_ID[5], char type_of_mammal, double angle, double distance);

sighting * insert_sighting(sighting * head, sighting * current_observer, sighting * observer_to_insert);

#endif //SIGHTINGS_SIGHTING_H
