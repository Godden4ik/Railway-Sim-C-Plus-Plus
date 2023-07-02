//
// Created by koyot on 02/07/2023.
//

#ifndef RAILWAYSIM_TRAIN_H
#define RAILWAYSIM_TRAIN_H

#include "../Railway/TrainStation.h"
#include <vector>
#include <functional>
#include <unordered_map>
#include <stack>

class Train {
    TrainStation currentStation;
    std::stack<TrainStation> path;

    bool DFS(const TrainStation& station, const TrainStation& target, std::unordered_map<TrainStation, bool> visited);

public:
    Train(const TrainStation& currentStation);
    void move();
    void setPathToStation(const TrainStation& endStation);
    TrainStation getCurrentStation() const;
    std::stack<TrainStation> getPath() const;

};
#endif //RAILWAYSIM_TRAIN_H
