//
//  bus_manager.hpp
//  w03-12-decomposition-2
//
//  Created by Sergey Gordeev on 15/01/2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#ifndef bus_manager_hpp
#define bus_manager_hpp

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "query.h"
#include "responses.h"


class BusManager {
public:
    void AddBus(const std::string& bus, const std::vector<std::string>& stops);

    BusesForStopResponse GetBusesForStop(const std::string& stop) const;

    StopsForBusResponse GetStopsForBus(const std::string& bus) const;

    AllBusesResponse GetAllBuses() const;

private:
    std::map<std::string, std::vector<std::string>> buses_to_stops;
    std::map<std::string, std::vector<std::string>> stops_to_buses;
};
#endif /* bus_manager_hpp */
