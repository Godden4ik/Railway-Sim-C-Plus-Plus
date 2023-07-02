//
// Created by koyot on 25/06/2023.
//

#include "RailNetwork.h"
#include <random>
#include <set>
#include <queue>
#include <functional>

RailNetwork::RailNetwork() = default;

void RailNetwork::generateStations(int number) {
    std::set<std::pair<int, int>> coordSet;
    std::random_device rd;
    std::mt19937 engine(rd());

    std::uniform_int_distribution distribution(0, 1000);


    while(coordSet.size() < number) {
        int randX = distribution(engine);
        int randY = distribution(engine);

        auto coordPair = std::make_pair(randX, randY);
        if (coordSet.find(coordPair) == coordSet.end()) {
            TrainStation station = TrainStation(randX, randY);
            trainStations.emplace_back(station);
            coordSet.insert(coordPair);
        }
    }
}

void RailNetwork::generateNetwork() {
    std::vector<bool> visited(trainStations.size(), false); // Keep track of visited stations
    std::vector<Route> mst; // Minimum spanning tree
    std::priority_queue<Route, std::vector<Route>, std::greater<>> pq; // Priority queue for routes

    visited[0] = true; // Start with the first station
    int visitedCount = 1;

    // Add routes from the first station to the priority queue
    for (const auto& station : trainStations) {
        pq.emplace(trainStations[0], station);
    }

    while (visitedCount < trainStations.size()) {
        Route minRoute = pq.top();
        pq.pop();

        const TrainStation& currentStation = minRoute.getStations().second;
        if (!visited[currentStation.index]) {
            visited[currentStation.index] = true;
            visitedCount++;

            mst.push_back(minRoute);

            // Add routes from the current station to the priority queue
            for (const auto& station : trainStations) {
                if (!visited[station.index]) {
                    pq.emplace(currentStation, station);
                }
            }
        }
    }

    routes = mst;
}

std::vector<TrainStation> RailNetwork::getStations() {
    return trainStations;
}
std::vector<Route> RailNetwork::getRoutes() {
    return routes;
}






