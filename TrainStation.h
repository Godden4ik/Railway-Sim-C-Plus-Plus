//
// Created by koyot on 25/06/2023.
//

#ifndef RAILWAYSIM_TRAINSTATION_H
#define RAILWAYSIM_TRAINSTATION_H


#include <utility>
#include <iostream>

class TrainStation {
private:
    int x;
    int y;
    static int currentIndex;
public:
    int index;
    TrainStation(int x, int y);
    TrainStation(TrainStation const &otherStation);
    ~TrainStation();
    std::pair<int, int> getCoordinates() const;
    static double getDistance(const TrainStation& station1, const TrainStation& station2);

    friend std::ostream& operator<<(std::ostream& os, const TrainStation& station);
};


#endif //RAILWAYSIM_TRAINSTATION_H
