//
//  assertation_tools.cpp
//  u-tests
//
//  Created by Sergey Gordeev on 16/01/2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#include "assertation_tools.hpp"

void AssertTrue ( const bool actual, const std::string& msg )
{
    AssertEq ( true, actual, msg );
}

void Assert ( const bool actual, const std::string& msg )
{
    AssertEq ( true, actual, msg );
}
