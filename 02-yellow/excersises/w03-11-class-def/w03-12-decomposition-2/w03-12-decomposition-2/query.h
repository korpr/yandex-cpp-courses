//
//  query.hpp
//  w03-12-decomposition-2
//
//  Created by Sergey Gordeev on 15/01/2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#ifndef query_hpp
#define query_hpp

#include <iostream>
#include <string>
#include <vector>

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    std::string bus;
    std::string stop;
    std::vector<std::string> stops;
};

std::istream& operator >> (std::istream& is, Query& q);

#endif /* query_hpp */
