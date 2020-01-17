//
//  main.cpp
//  w03-14-sets-partition
//
//  Created by Sergey Gordeev on 17/01/2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#include <iostream>
#include <string>
#include "set-func.hpp"
#include "test_runner.hpp"
#include "assertation_tools.hpp"

void TestEmpty(){
    AssertEq(0, FindGreaterElements(std::set<int>{}, 5).size(), "Empty Set");
}
void TestBorderCondition(){
    
    
    AssertEq(0, FindGreaterElements(std::set<int>{5,4,3,2,1}, 5).size(),
             "5,4,3,2,1 border is very right(5)");
    {
        std::vector<int> expected = {2,3,4,5};
        AssertEq(expected, FindGreaterElements(std::set<int>{5,4,3,2,1}, 1),
                 "5,4,3,2,1 border is very left(1)");
    }
    {
        std::vector<int> expected = {1,2,3,4,5};
        AssertEq(expected, FindGreaterElements(std::set<int>{5,4,3,2,1}, -1),
                 "5,4,3,2,1 all element gt border");
    }
    AssertEq(0, FindGreaterElements(std::set<int>{5,4,3,2,1}, 6).size(),
             "5,4,3,2,1  all element less than border");
}
void Test(){
    std::vector<int> expected = {4,5};
    AssertEq(expected, FindGreaterElements(std::set<int>{5,4,3,2,1}, 3),
             "5,4,3,2,1 border is 3)");
}

int main(int argc, const char * argv[]) {
    
    TestRunner r;
    r.RunTest(Test, "standart behavior");
    r.RunTest(TestBorderCondition, "TestBorderCondition");
    r.RunTest(TestEmpty, "TestEmpty");
    return 0;
}
