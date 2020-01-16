//
//  responses.hpp
//  w03-12-decomposition-2
//
//  Created by Sergey Gordeev on 15/01/2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#ifndef responses_hpp
#define responses_hpp

#include <iostream>
#include <vector>
#include <string>
#include <map>

struct BusesForStopResponse {
    std::vector<std::string> buses;
};

std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
    std::string bus;
    std::vector<std::pair<std::string, std::vector<std::string>>> stops_for_buses;
};

std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
    std::map<std::string, std::vector<std::string>> buses_to_stops;
};

std::ostream& operator << (std::ostream& os, const AllBusesResponse& r);

#endif /* responses_hpp */
