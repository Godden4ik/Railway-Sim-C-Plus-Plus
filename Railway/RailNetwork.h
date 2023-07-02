//
// Created by koyot on 25/06/2023.
//

#ifndef RAILWAYSIM_RAILNETWORK_H
#define RAILWAYSIM_RAILNETWORK_H


#include "TrainStation.h"
#include "Route.h"
#include <vector>

class RailNetwork {
public:
    static std::vector<Route> routes;
    static std::vector<TrainStation> trainStations;

    RailNetwork();

    static void generateStations(int number);

    static void generateNetwork();

    //std::vector<TrainStation> getStations();
    //std::vector<Route> getRoutes();


};


#endif //RAILWAYSIM_RAILNETWORK_H
