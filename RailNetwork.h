//
// Created by koyot on 25/06/2023.
//

#ifndef RAILWAYSIM_RAILNETWORK_H
#define RAILWAYSIM_RAILNETWORK_H


#include "TrainStation.h"
#include "Route.h"
#include <vector>

class RailNetwork {
private:
    std::vector<TrainStation> trainStations;
    std::vector<Route> routes;

public:
    RailNetwork();

    void generateStations(int number);

    void generateNetwork();

    std::vector<TrainStation> getStations();
    std::vector<Route> getRoutes();


};


#endif //RAILWAYSIM_RAILNETWORK_H
