//
// Created by koyot on 25/06/2023.
//

#include "TrainStation.h"
#include <iostream>
#include <cmath>

int TrainStation::currentIndex = 0;

TrainStation::TrainStation(int x, int y)
    :x(x), y(y), index(currentIndex++)
    {}

TrainStation::TrainStation(TrainStation const &otherStation)
    :x(otherStation.x), y(otherStation.y), index(otherStation.index){}

TrainStation::~TrainStation()= default;

std::pair<int, int> TrainStation::getCoordinates() const{
    return std::pair<int,int>{x, y};
}

double TrainStation::getDistance(const TrainStation& station1, const TrainStation& station2) {
    auto station1Coords = station1.getCoordinates();
    auto station2Coords = station2.getCoordinates();

    double station1X = station1Coords.first;
    double station1Y = station1Coords.second;
    double station2X = station2Coords.first;
    double station2Y = station2Coords.second;

    double distanceX = station2X - station1X;
    double distanceY = station2Y - station1Y;

    return sqrt(distanceX * distanceX + distanceY * distanceY);
}



std::ostream& operator<<(std::ostream& os, const TrainStation& station) {
    std::pair<int, int> coordinates = station.getCoordinates();
    os << "TrainStation " << station.index << ": (" << coordinates.first << ", " << coordinates.second << ")";
    return os;
}
