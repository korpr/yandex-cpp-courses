//
//  main.cpp
//  w04-19-merge-sort
//
//  Created by Sergey Gordeev on 20/01/2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#include <iostream>
#include "merge-sort.cpp"
#include "test_runner.hpp"
#include "assertation_tools.hpp"
#include <vector>

void Test(){
    {
        std::vector<int> expected = {};
        std::vector<int> target = {};
        MergeSort(begin(target), end(target));
        AssertEq(expected,target, "{}");
    }
    {
        std::vector<int> expected = {0};
        std::vector<int> target = {0};
        MergeSort(begin(target), end(target));
        AssertEq(expected,target, "{0}");
    }
}


void Test2(){
    
    {
        std::vector<int> expected = {1,2,3,4};
        std::vector<int> target = {1,2,3,4};
        MergeSort(begin(target), end(target));
        AssertEq(expected,target, "{1,2,3,4}");
    }
    {
        std::vector<int> expected = {1,2,3,4};
        std::vector<int> target = {4,3,2,1};
        MergeSort(begin(target), end(target));
        AssertEq(expected,target, "{4,3,2,1}");
    }
    {
        std::vector<int> expected = {1,1};
        std::vector<int> target = {1,1};
        MergeSort(begin(target), end(target));
        AssertEq(expected,target, "{1, 1}");
    }
    {
        std::vector<int> expected = {1,2};
        std::vector<int> target = {2,1};
        MergeSort(begin(target), end(target));
        AssertEq(expected,target, "{2, 1}");
    }
    {
        std::vector<int> expected = {0,1,2,4};
        std::vector<int> target = {1,2,4,0};
        MergeSort(begin(target), end(target));
        AssertEq(expected,target, "{1,2,4,0}");
    }
}
void Test3(){
    
    {
        std::vector<int> expected = {1,2,3};
        std::vector<int> target = {1,2,3};
        MergeSort(begin(target), end(target));
        AssertEq(expected,target, "{1,2,3}");
    }
    {
        std::vector<int> expected = {2,3,4};
        std::vector<int> target = {4,3,2};
        MergeSort(begin(target), end(target));
        AssertEq(expected,target, "{4,3,2}");
    }
    {
        std::vector<int> expected = {1,1,1};
        std::vector<int> target = {1,1,1};
        MergeSort(begin(target), end(target));
        AssertEq(expected,target, "{1, 1, 1}");
    }
    {
        std::vector<int> expected = {1,2,2};
        std::vector<int> target = {2,1,2};
        MergeSort(begin(target), end(target));
        AssertEq(expected,target, "{2, 1}");
    }
    {
        std::vector<int> expected = {0,1,2,3,4,5,7,8,9};
        std::vector<int> target = {4,3,7,2,1,5,8,9,0};
        MergeSort(begin(target), end(target));
        AssertEq(expected,target, "{4,3,7,2,1,5,8,9,0}");
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TestRunner r;
    r.RunTest(Test, "Test");
    r.RunTest(Test2, "Test2");
    r.RunTest(Test3, "Test3");
    return 0;
}
