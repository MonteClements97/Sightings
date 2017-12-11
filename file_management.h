#ifndef SIGHTINGS_FILE_MANAGEMENT_H
#define SIGHTINGS_FILE_MANAGEMENT_H

#include "observers.h"
#include "sightings.h"

FILE * open_file (char observer_or_sighting);

observer * read_observer_file(FILE * observer_file);
sighting * read_sighting_file(FILE * sighting_file);

#endif //SIGHTINGS_FILE_MANAGEMENT_H
