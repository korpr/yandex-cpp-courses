//
//  main.cpp
//  w03-15-split-words
//
//  Created by Sergey Gordeev on 17/01/2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#include <iostream>
#include "test_runner.hpp"
#include "assertation_tools.hpp"
#include "split-func.hpp"

void Border(){
    AssertEq(0, SplitIntoWords("").size(), "Empty string");
     AssertEq(0, SplitIntoWords(" ").size(), "'_'");
    AssertEq(1, SplitIntoWords(" a ").size(), "'_a_'");
    AssertEq(1, SplitIntoWords("  a  ").size(), "'__a__'");
    AssertEq(2, SplitIntoWords("  a a ").size(), "'__a_a_'");
    AssertEq(2, SplitIntoWords(" a  a ").size(), "'_a__a_'");
    std::vector<std::string> expected = {"a","b"};
    AssertEq(expected, SplitIntoWords(" a  b "), "'_a__b_'");
}

void Test(){
    {
        std::vector<std::string> expected = {"C", "Cpp", "Java", "Python"};
        AssertEq(expected, SplitIntoWords("C Cpp Java Python"), "C Cpp Java Python");
    }
    {
        std::vector<std::string> expected = {"C"};
        AssertEq(expected, SplitIntoWords("C"), "C");
    }
}

int main(int argc, const char * argv[]) {
    TestRunner r;
    r.RunTest(Border, "Border");
    r.RunTest(Test, "Test");
    return 0;
}
