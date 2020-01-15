#include <iostream>
#include "TestRunner.h"

void AssertEqTest()
{
    AssertEq ( 1, 1, "first" );
    AssertEq ( 2, 2, "failed" );
    
}

void AssertTrueTest()
{
    AssertTrue ( true, "first" );
    AssertTrue ( false, "failed" );
    
}
int main ( int argc, char **argv )
{

    {
        TestRunner runner;
        runner.runTest ( AssertEqTest, "first test" );
        runner.runTest ( AssertTrueTest, "second test" );
    }
    return 0;
}
