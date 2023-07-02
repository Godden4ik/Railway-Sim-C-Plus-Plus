#include <iostream>
#include "Railway/RailNetwork.h"
#include "Train/Train.h"

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    RailNetwork();
    RailNetwork::generateStations(10);
    RailNetwork::generateNetwork();

    auto stations = RailNetwork::trainStations;
    auto train = Train(stations[0]);
    train.setPathToStation(stations[1]);
    std::cout<<"Current station: "<<train.getCurrentStation()<<"\n";
    std::cout<<"Destination: "<<stations[1]<<"\n";

    auto path = train.getPath();

    while(!path.empty()) {
        std::cout<<path.top()<<"\n";
        path.pop();
    }

    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Time taken by function: "
         << duration.count() << " microseconds" << std::endl;


}
