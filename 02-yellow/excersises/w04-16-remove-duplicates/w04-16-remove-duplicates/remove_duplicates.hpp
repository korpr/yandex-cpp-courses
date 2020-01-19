//
//  remove_duplicates.hpp
//  w04-16-remove-duplicates
//
//  Created by Sergey Gordeev on 19/01/2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#ifndef remove_duplicates_hpp
#define remove_duplicates_hpp

#include <stdio.h>
#include <vector>
#include <algorithm>

template <typename T>
void RemoveDuplicates(std::vector<T>& elements){
    if (elements.empty()){
        return;
    }
    std::sort(begin(elements),end(elements));
    auto newEnd = std::unique(begin(elements), end(elements));
    elements.erase(newEnd, end(elements));
}

#endif /* remove_duplicates_hpp */
