//
//  main.cpp
//  w04-20-find-nearest-element
//
//  Created by Sergey Gordeev on 21/01/2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#include <iostream>
#include <set>
#include "find-nearest-element.hpp"
#include "test_runner.hpp"
#include "assertation_tools.hpp"


void TestEmpty(){
    std::set<int> s = {};
    AssertTrue(s.begin() == FindNearestElement(s,100),"Epmty");
};

void Test(){
    {
        std::set<int> s = {1,3,6,8,34,99,100};
        AssertEq(100, *FindNearestElement(s,100), "100 =>{1,3,6,8,34,99,100}" );
        AssertEq(1, *FindNearestElement(s,2), "2 =>{1,3,6,8,34,99,100}");
        AssertEq(1, *FindNearestElement(s,1), "1 =>{1,3,6,8,34,99,100}");
        AssertEq(99, *FindNearestElement(s,80), "96 =>{1,3,6,8,34,99,100}");
    }
    
    {
        std::set<int> s = {1, 4, 6};
        AssertEq(1, *FindNearestElement(s,0), "0 =>{1, 4, 6}");
        AssertEq(4, *FindNearestElement(s,3), "3 =>{1, 4, 6}");
        AssertEq(4, *FindNearestElement(s,5), "5 =>{1, 4, 6}");
        AssertEq(6, *FindNearestElement(s,6), "6 =>{1, 4, 6}");
        AssertEq(6, *FindNearestElement(s,80), "100 =>{1, 4, 6}");
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TestRunner r;
    r.RunTest(Test,"Test");
    r.RunTest(TestEmpty,"TestEmpty");
    return 0;
}
