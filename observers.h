
#ifndef SIGHTINGS_OBSERVERS_H
#define SIGHTINGS_OBSERVERS_H

typedef struct s_observer {
    char observer_ID[5];
    double latitude;
    double longitude;
    struct s_observer * pointer;
} observer;

observer * create_observer(char observer_ID[5], double latitude, double longitude);

observer * insert_observer(observer * head, observer * observer_to_insert);

#endif //SIGHTINGS_OBSERVERS_H
