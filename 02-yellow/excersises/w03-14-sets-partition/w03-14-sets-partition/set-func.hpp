//
//  set-func.hpp
//  w03-14-sets-partition
//
//  Created by Sergey Gordeev on 17/01/2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#ifndef set_func_hpp
#define set_func_hpp

#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

template <typename T>
std::vector<T> FindGreaterElements(const std::set<T>& elements, const T& border){
    auto borderIt = find_if(begin(elements),end(elements),
                            [border](T e){return e > border;});
    return {borderIt, end(elements)};
}
#endif /* set_func_hpp */
