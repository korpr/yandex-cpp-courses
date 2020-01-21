//
//  find-nearest-element.cpp
//  w04-20-find-nearest-element
//
//  Created by Sergey Gordeev on 21/01/2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#include "find-nearest-element.hpp"

std::set<int>::const_iterator FindNearestElement(const std::set<int>& numbers, int border){
    
    const auto lower = numbers.lower_bound(border);//not less
    
    if (lower == numbers.begin()){
        return lower;
    }
    const auto lest_lower = prev(lower);
    if (lower == numbers.end()) {
        return lest_lower;
    }
    
    return border - *lest_lower <= *lower - border? lest_lower:lower;
}
