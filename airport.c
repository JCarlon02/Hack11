#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "airport.h"

Airport* createAirport(const char* gpsId,
                       const char* type,
                       const char* name,
                       double latitude,
                       double longitude,
                       int elevationFeet,
                       const char* city,
                       const char* countryAbbrv){

if(gpsId == NULL || type == NULL || name == NULL || city == NULL || countryAbbrv == NULL){
  return NULL;
}
if(latitude < -90 || latitude > 90 || longitude < -180 || longitude > 180){
  return 1;
}

Airport* create = (Airport*) malloc(sizeof(Airport) * 1);

create->gpsId = (char*) malloc(sizeof(char) * (strlen(gpsId + 1)));
strcpy(create->gpsId, gpsId);
create->type = (char*) malloc(sizeof(char) * (strlen(type + 1)));
strcpy(create->type, type);
create->name = (char*) malloc(sizeof(char) * (strlen(name + 1)));
strcpy(create->name, name);
create->latitude = latitude;
create->longitude = longitude;
create->elevationFeet = elevationFeet;
create->city = (char*) malloc(sizeof(char) * (strlen(city + 1)));
strcpy(create->city, city);
create->countryAbbrv = (char*) malloc(sizeof(char) * (strlen(countryAbbrv + 1)));
strcpy(create->countryAbbrv, countryAbbrv);

return create;


}

void initAirport(Airport* airport,
                 const char* gpsId,
                 const char* type,
                 const char* name,
                 double latitude,
                 double longitude,
                 int elevationFeet,
                 const char* city,
                 const char* countryAbbrv){

   airport->gpsId = (char*) malloc(sizeof(char) * (strlen(gpsId + 1)));
   strcpy(airport->gpsId, gpsId);
   airptor->type = (char*) malloc(sizeof(char) * (strlen(type + 1)));
   strcpy(airport->type, type);
   airport->name = (char*) malloc(sizeof(char) * (strlen(name + 1)));
   strcpy(airport->name, name);
   airport->latitude = latitude;
   airport->longitude = longitude;
   airport->elevationFeet = elevationFeet;
   airport->city = (char*) malloc(sizeof(char) * (strlen(city + 1)));
   strcpy(airport->city, city);
   airport->countryAbbrv = (char*) malloc(sizeof(char) * (strlen(countryAbbrv + 1)));
   strcpy(airport->countryAbbrv, countryAbbrv)
return;


}


char* airportToString(const Airport* a){


}


double getAirDistance(const Airport* origin, const Airport* destination){

double lat1 = ((origin->latitude) / 180) * M_PI;
double long1 = ((origin->longitude) / 180) * M_PI;
double lat2 = ((destination->latitude) / 180) * M_PI;
double long2 = ((destination->longitude) / 180) * M_PI;
double airDistance = (acos(((sin(lat1)) * sin(lat2)) + (cos(lat1) * cos(lat2) * cos(long2 - long1))) * 6371);

return airDistance;

}

double getEstimatedTravelTime(const Airport* stops,
                              int size,
                              double aveKmsPerHour,
                              double aveLayoverTimeHrs){

if(stops == NULL){
  return 1;
}

double distance = 0;
for(int i = 1; i < size; i++){
  distance += getAirDistance(&stops[i - 1], &stops[i]);
}

double time = distance / aveKmsPerHour;
double newTime = time + (aveLayoverTimeHrs * (size - 2));

return newTime;

}
