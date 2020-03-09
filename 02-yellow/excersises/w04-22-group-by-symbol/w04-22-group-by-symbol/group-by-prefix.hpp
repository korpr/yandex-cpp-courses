//
//  group-by-symbol.hpp
//  w04-22-group-by-symbol
//
//  Created by Sergey Gordeev on 22/01/2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

template <typename RandomIt>
std::pair<RandomIt, RandomIt> FindStartsWith(
                                             RandomIt range_begin,
                                             RandomIt range_end,
                                             char prefix
                                             ){
    auto diapason_start = find_if(range_begin,range_end,[prefix](typename RandomIt::value_type e){
        return e[0] == prefix;
    });
    auto diapason_end = find_if(range_begin,range_end,[prefix](typename RandomIt::value_type e){
        return e[0] > prefix;
    });
    if (diapason_start == range_end){
        return std::make_pair(diapason_end, diapason_end);
    }
    
    return std::make_pair(diapason_start,diapason_end);
}

template <typename RandomIt>
std::pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const std::string& prefix){
    
    auto diapason_start = find_if(range_begin,range_end,[prefix](typename RandomIt::value_type e){
        return e.find_first_of(prefix) == 0;
    });
    
    std::string new_prefix = prefix;
    new_prefix[prefix.size()-1]++;
    auto diapason_end = find_if(range_begin, range_end,[new_prefix](typename RandomIt::value_type e){
        return static_cast<std::string>(e) > new_prefix;
    });
    if (diapason_start == range_end){
        return std::make_pair(diapason_end, diapason_end);
    }
    
    return std::make_pair(diapason_start,diapason_end);
}
