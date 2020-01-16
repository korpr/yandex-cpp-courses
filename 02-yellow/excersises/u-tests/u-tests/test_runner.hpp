//
//  test_runner.hpp
//  u-tests
//
//  Created by Sergey Gordeev on 16/01/2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#pragma once

#include <string>
#include <iostream>

class TestRunner
{
private:
    unsigned int failedCount;
public:
    TestRunner();
    ~TestRunner();

    template <class TestFunc>
    void RunTest ( TestFunc func, const std::string& name )
    {
        {
            try {
                func();
                std::cerr << "[  OK  ] " ;
            } catch ( const std::exception& e ) {
                ++failedCount;
                std::cerr << "[ FAIL ] " << " reason: " << e.what();
            }
            std::cerr <<" "<< name << std::endl;
        }
    }
    
};
