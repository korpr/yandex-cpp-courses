//
//  main.cpp
//  w03-11-class-def
//
//  Created by Sergey Gordeev on 15/01/2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#include <iostream>
#include "rectangle.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    Rectangle r {3,4};
    std::cout << "Hello, World!\n" << r.GetArea();
    return 0;
}
