//
//  main.cpp
//  w03-13-vectors-part
//
//  Created by Sergey Gordeev on 16/01/2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#include <iostream>
#include "vector_tools.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    PrintVectorPart({6, 1, 8, -5, 4});
    std::cout << std::endl;
    PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
    std::cout << std::endl;
    PrintVectorPart({6, 1, 8, 5, 4});
    std::cout << std::endl;
    PrintVectorPart({6, 1, 8, -5});
    std::cout << std::endl;
    
    return 0;
}
