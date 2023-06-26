//
// Created by koyot on 25/06/2023.
//

#ifndef RAILWAYSIM_ROUTE_H
#define RAILWAYSIM_ROUTE_H


#include "TrainStation.h"

class Route {
private:
    std::pair<TrainStation, TrainStation> route;
public:
    Route(const TrainStation& station1, const TrainStation& station2);
    double getLength() const;
    std::pair<const TrainStation&, const TrainStation&> getStations();

    friend std::ostream& operator<<(std::ostream& os, const Route& route);
    friend bool operator<(const Route& route1, const Route& route2);
    friend bool operator>(const Route& route1, const Route& route2);
};


#endif //RAILWAYSIM_ROUTE_H
