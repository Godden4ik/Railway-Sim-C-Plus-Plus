//
// Created by koyot on 25/06/2023.
//

#include "Route.h"

Route::Route(const TrainStation& station1, const TrainStation& station2):
    route(std::make_pair(station1, station2)) {}
double Route::getLength() const {
    return TrainStation::getDistance(route.first, route.second);
}



std::pair<const TrainStation&, const TrainStation&> Route::getStations() {
    return route;
}

std::ostream& operator<<(std::ostream& os, const Route& route) {
    return os << "Route between " << route.route.first << " and " << route.route.second
        << " with a distance of " << route.getLength() << " km";
}

bool operator<(const Route& route1, const Route& route2) {
    return route1.getLength() < route2.getLength();
}

bool operator>(const Route& route1, const Route& route2) {
    return route1.getLength() > route2.getLength();
}

