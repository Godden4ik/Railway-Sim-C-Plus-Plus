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

TrainStation::TrainStation(TrainStation const &otherStation) = default;

TrainStation::~TrainStation()= default;

std::pair<int, int> TrainStation::getCoordinates() const{
    return std::pair<int,int>{x, y};
}

 int TrainStation::getIndex() const{
    return index;
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

bool operator==(const TrainStation& lhs, const TrainStation& rhs) {
    return lhs.getIndex() == rhs.getIndex();
}

std::ostream& operator<<(std::ostream& os, const TrainStation& station) {
    std::pair<int, int> coordinates = station.getCoordinates();
    os << "TrainStation " << station.index << ": (" << coordinates.first << ", " << coordinates.second << ")";
    return os;
}


