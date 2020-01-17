//
//  vector_tools.cpp
//  w03-13-vectors-part
//
//  Created by Sergey Gordeev on 16/01/2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#include "vector_tools.hpp"
#include <algorithm>

void PrintVectorPart(const std::vector<int>& numbers)
{
    auto border = std::find_if(begin(numbers),end(numbers),[](const int& e){return e<0;});

    while(border != begin(numbers)){
         std::cout << *(--border) << " ";
    }
}
