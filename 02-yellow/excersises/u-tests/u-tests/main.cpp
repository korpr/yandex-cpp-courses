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

void AssertSetTest()
{
    std::set<int> expected = {1,2};
    std::set<int> another = {1,2,3};
    AssertEq ( expected, expected,"set  eq" );
    AssertEq ( expected, another , "set not eq");
    
}
int main ( int argc, char **argv )
{
    
    {
        TestRunner runner;
        runner.RunTest ( AssertEqTest, "AssertEqTest" );
        runner.RunTest ( AssertTrueTest, "AssertTrueTest" );
        runner.RunTest ( AssertSetTest, "AssertSetTest" );
    }
    return 0;
}
