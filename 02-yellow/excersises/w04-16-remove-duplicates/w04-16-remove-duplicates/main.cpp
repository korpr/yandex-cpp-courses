//
//  main.cpp
//  w04-16-remove-duplicates
//
//  Created by Sergey Gordeev on 19/01/2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "remove_duplicates.hpp"
#include "test_runner.hpp"
#include "assertation_tools.hpp"

void Test(){
    {
        std::vector<int> expected = {0,1,4,6,7};
        std::vector<int> actual ={6, 4, 7, 6, 4, 4, 0, 1};
        RemoveDuplicates(actual);
        std::sort(begin(actual), end(actual));
        AssertEq(expected,actual,"6, 4, 7, 6, 4, 4, 0, 1");
    }
    
    {
        std::vector<std::string> expected = {"C","C++"};
        std::vector<std::string> actual ={"C", "C++", "C++", "C", "C++"};
        RemoveDuplicates(actual);
        std::sort(begin(actual), end(actual));
        AssertEq(expected, actual,"C, C++, C++, C, C++");
    }
    
    {
        std::vector<std::string> expected = {"C","C++","c"};
        
        std::vector<std::string> actual ={"C", "C++", "C++", "C","c" , "C++", "c"};
        RemoveDuplicates(actual);
        std::sort(begin(actual), end(actual));
        AssertEq(expected, actual,"C, C++, C++, C, c, C++, c");
    }
}

void Empty(){
    {
        std::vector<int> expected = {};
        std::vector<int> actual ={};
        RemoveDuplicates(actual);
        std::sort(begin(actual), end(actual));
        AssertEq(expected, actual,"Empty");
    }
}

void AllDuplicates(){
    {
        std::vector<int> expected = {0};
        std::vector<int> actual ={0,0,0,0,0,0};
        RemoveDuplicates(actual);
        std::sort(begin(actual), end(actual));
        AssertEq(expected, actual,"0, 0, 0, 0, 0, 0");
    }
    
    {
        std::vector<std::string> expected = {"C"};
        std::vector<std::string> actual = {"C", "C", "C", "C", "C"};
        RemoveDuplicates(actual);
        std::sort(begin(actual), end(actual));
        AssertEq(expected, actual,"C, C, C, C, C,");
    }
    
}
int main(int argc, const char * argv[]) {
    TestRunner runner;
    
    runner.RunTest(Empty,"Empty");
    runner.RunTest(AllDuplicates,"AllDuplicates");
    runner.RunTest(Test,"Test");
    return 0;
}
