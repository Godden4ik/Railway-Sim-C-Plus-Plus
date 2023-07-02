//
// Created by koyot on 02/07/2023.
//
#include "Train.h"
#include "../Railway/RailNetwork.h"
#include "../Railway/Route.h"

#include <vector>
#include <unordered_map>
#include <functional>

namespace std {
    template <>
    struct hash<TrainStation> {
        std::size_t operator()(const TrainStation& station) const {
            size_t hashValue = 0;
            hashValue ^= std::hash<int>()(station.getIndex());
            return hashValue;
        }
    };
}

Train::Train(const TrainStation& currentStation) : currentStation(currentStation) {}

void Train::setPathToStation(const TrainStation& endStation) {
    std::unordered_map<TrainStation, bool> visited;

    for(auto &trainStation: RailNetwork::trainStations) {
        visited[trainStation] = false;
    }

    visited[currentStation] = true;

    DFS(currentStation, endStation, visited);


}

bool Train::DFS(const TrainStation& station, const TrainStation& target, std::unordered_map<TrainStation, bool> visited) {

    for(auto &route: RailNetwork::routes) {
        auto stationPair = route.getStations();
        if(stationPair.first == station && !visited[stationPair.second]) {
            visited[stationPair.second] = true;
            if(stationPair.second == target) {
                path.push(stationPair.second);
                //std::cout<<stationPair.second<<"\n";
                return true;
            }
            if(DFS(stationPair.second, target, visited)) {
                path.push(stationPair.second);
                //std::cout<<stationPair.second<<"\n";
                return true;
            }
        }
        else if(stationPair.second == station && !visited[stationPair.first]) {
            visited[stationPair.first] = true;

            if(stationPair.first == target) {
                path.push(stationPair.first);
                //std::cout<<stationPair.first<<"\n";
                return true;
            }
            if(DFS(stationPair.first, target, visited)) {
                path.push(stationPair.first);
                //std::cout<<stationPair.first<<"\n";
                return true;
            }
        }
    }
}

TrainStation Train::getCurrentStation() const {
    return currentStation;
}

std::stack<TrainStation> Train::getPath() const{
    return path;
}

void Train::move() {}