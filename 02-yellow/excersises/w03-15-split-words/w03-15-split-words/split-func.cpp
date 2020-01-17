//
//  split-func.cpp
//  w03-15-split-words
//
//  Created by Sergey Gordeev on 17/01/2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#include "split-func.hpp"
#include <algorithm>
std::vector<std::string> SplitIntoWords(const std::string& s){
    
    if (s.empty()){
        return {};
    }
    
    auto beginIt = begin(s);
    const auto& endIt = end(s);
    
    std::vector<std::string> result;
    while(beginIt != endIt){
        if (*beginIt == ' '){
            ++beginIt;
            continue;
        }
        auto space = find(beginIt, endIt,' ');
        result.push_back({beginIt,space});
        beginIt = space;
    }
    
    return result;
}
