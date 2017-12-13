
#ifndef SIGHTINGS_CONVERSION_USING_MATH_H
#define SIGHTINGS_CONVERSION_USING_MATH_H


void find_and_store_locations(observer * observers, sighting * sightings);
double * get_location(double observer_latitude, double observer_longitude, double bearing, double distance);

#endif //SIGHTINGS_CONVERSION_USING_MATH_H
