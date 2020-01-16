//
//  main.cpp
//  u-tests
//
//  Created by Sergey Gordeev on 16/01/2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#include <iostream>
#include "test_runner.hpp"
#include "assertation_tools.hpp"

void AssertEqTest()
{
    AssertEq ( 1, 1, "1 == 1" );
    AssertEq ( 2, 2, " 2 == 2" );
}

void AssertTrueTest()
{
    AssertTrue ( true, "true == true " );
    AssertTrue ( false, "true != false" );
    
}
int main ( int argc, char **argv )
{

    {
        TestRunner runner;
        runner.RunTest ( AssertEqTest, "first test" );
        runner.RunTest ( AssertTrueTest, "second test" );
    }
    return 0;
}
