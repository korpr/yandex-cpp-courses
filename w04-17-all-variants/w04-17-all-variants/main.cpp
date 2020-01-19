//
//  main.cpp
//  w04-17-all-variants
//
//  Created by Sergey Gordeev on 19/01/2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#include <iostream>
#include <vector>
#include "test_runner.hpp"
#include "assertation_tools.hpp"
#include "permutator.hpp"

void Test(){
    {
        std::vector<std::vector<int>> expected ={
            {1}
        };
        AssertEq(expected, AllPermutations(1), "For 1");
    }
    {
        std::vector<std::vector<int>> expected ={
            {2,1},
            {1,2}
        };
        AssertEq(expected, AllPermutations(2), "For 2");
    }
    
    {
        std::vector<std::vector<int>> expected ={
            {3, 2, 1},
            {3, 1, 2},
            {2, 3, 1},
            {2, 1, 3},
            {1, 3, 2},
            {1 ,2, 3},
        };
        AssertEq(expected, AllPermutations(3), "For 3");
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    TestRunner r;
    r.RunTest(Test,"Test");
    //TODO:: place code  for  test system
    return 0;
}
