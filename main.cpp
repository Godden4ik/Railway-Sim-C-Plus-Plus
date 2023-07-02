#include <iostream>
#include "RailNetwork.h"

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    RailNetwork railNetwork = RailNetwork();
    railNetwork.generateStations(100);
    railNetwork.generateNetwork();
    auto routes = railNetwork.getRoutes();

    auto stations = railNetwork.getStations();
    for(auto& route: routes) {
        std::cout<<route<<"\n";
    }

    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Time taken by function: "
         << duration.count() << " microseconds" << std::endl;


}
