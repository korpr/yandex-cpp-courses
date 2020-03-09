//
//  event_parser.cpp
//  w06-28-capstone
//
//  Created by Sergey Gordeev on 28.02.2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#include "event_parser.hpp"

std::string ParseEvent(std::istream& is) {
    std::string event;
    getline(is >> std::ws, event,'\n');
    return event;
}
