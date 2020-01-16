//
//  test_runner.cpp
//  u-tests
//
//  Created by Sergey Gordeev on 16/01/2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#include "test_runner.hpp"

TestRunner::TestRunner() : failedCount ( 0 ) {} ;
TestRunner::~TestRunner()
{
    if ( failedCount ) {
        std::cerr << failedCount << " unit tests failed. Terminate" << std::endl;
        exit ( 1 );
    }
}
