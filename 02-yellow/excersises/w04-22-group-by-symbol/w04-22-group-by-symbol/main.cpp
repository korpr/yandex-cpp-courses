//
//  main.cpp
//  w04-22-group-by-symbol
//
//  Created by Sergey Gordeev on 22/01/2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "test_runner.hpp"
#include "assertation_tools.hpp"
#include "group-by-prefix.hpp"
void TestByStringBorders(){
    
    const std::vector<std::string> empty;
    const auto answer_1 = FindStartsWith(empty.begin(), empty.end(), "1");
    AssertTrue(answer_1.first == answer_1.second ,"1=>[]:iterator are same");
    AssertEq(0, answer_1.first - empty.begin(),"1=>[]:insert into begin");
    
    const  std::vector<std::string> ones = {"10,11,12,13"};
    
    const auto answer_0 = FindStartsWith(ones.begin(), ones.end(), "0");
    AssertTrue(answer_0.first == answer_0.second , "0=>[10,11,12,13]:iterator are same");
    AssertEq(0, answer_0.first - ones.begin(), "0=>[10,11,12,13]:insert into begin");
    
    const auto answer_2 = FindStartsWith(ones.begin(), ones.end(), "2");
    AssertTrue(answer_2.first == answer_2.second ,"2=>[10,11,12,13]:iterator are same");
    AssertEq(ones.size(), answer_2.first - ones.begin(),"2=>[10,11,12,13]:insert into end");
}

void TestByFirstString(){
    
    const std::vector<std::string> someVals = {"11","12","13","21","41"};
    const auto answer_0 = FindStartsWith(someVals.begin(), someVals.end(), "0");
    AssertTrue(answer_0.first == answer_0.second ,"0=>[11,12,13,21,41]:iterators are same");
    AssertEq(0, answer_0.first - someVals.begin(),"0=>[11,12,13,21,41]:insert into begin");
    const auto answer_3 = FindStartsWith(someVals.begin(), someVals.end(), "3");
    AssertTrue(answer_3.first == answer_3.second ,"3=>[11,12,13,21,41]:iterators are same");
    AssertEq("41", *answer_3.first, "3=>[11,12,13,21,41]:insert before 41");
    
    const auto answer_1 = FindStartsWith(someVals.begin(), someVals.end(),"1");
    AssertTrue(answer_1.first != answer_1.second ,"1=>[11,12,13,21,41]:iterators aren't same");
    AssertEq("11", *answer_1.first,"1=>[11,12,13,21,41]: start with 11");
    AssertEq("21", *answer_1.second,"1=>[11,12,13,21,41]: start with 21");
    
    const std::vector<std::string> sorted_strings = {"moscow", "murmansk", "vologda"};
    const auto answer_m = FindStartsWith(sorted_strings.begin(), sorted_strings.end(), "m");
    AssertEq("moscow", *answer_m.first,"moscow == moscow");
    AssertEq("vologda", *answer_m.second,"vologda == vologda");
    
    const auto answer_p = FindStartsWith(sorted_strings.begin(), sorted_strings.end(), "p");
    AssertTrue(answer_p.first == answer_p.second ,"p=>[moscow, murmansk, vologda]:iterators are same");
    AssertEq(2, answer_p.first - sorted_strings.begin(),"p=>[moscow, murmansk, vologda]:insert idx == 2");
    
    
    const auto answer_z = FindStartsWith(sorted_strings.begin(), sorted_strings.end(), "z");
    AssertTrue(answer_z.first == answer_z.second ,"z=>[moscow, murmansk, vologda]:iterators are same");
    AssertEq(3, answer_z.first - sorted_strings.begin(),"p=>[moscow, murmansk, vologda]:insert idx == 3");
}
void TestByFirstCharBorders(){
    
    const std::vector<std::string> empty;
    const auto answer_1 = FindStartsWith(empty.begin(), empty.end(), '1');
    AssertTrue(answer_1.first == answer_1.second ,"1=>[]:iterator are same");
    AssertEq(0, answer_1.first - empty.begin(),"1=>[]:insert into begin");
    
    const  std::vector<std::string> ones = {"10,11,12,13"};
    
    const auto answer_0 = FindStartsWith(ones.begin(), ones.end(), '0');
    AssertTrue(answer_0.first == answer_0.second , "0=>[10,11,12,13]:iterator are same");
    AssertEq(0, answer_0.first - ones.begin(), "0=>[10,11,12,13]:insert into begin");
    
    const auto answer_2 = FindStartsWith(ones.begin(), ones.end(), '2');
    AssertTrue(answer_2.first == answer_2.second ,"2=>[10,11,12,13]:iterator are same");
    AssertEq(ones.size(), answer_2.first - ones.begin(),"2=>[10,11,12,13]:insert into end");
}

void TestByFirstChar(){
    
    const std::vector<std::string> someVals = {"11","12","13","21","41"};
    const auto answer_0 = FindStartsWith(someVals.begin(), someVals.end(), '0');
    AssertTrue(answer_0.first == answer_0.second ,"0=>[11,12,13,21,41]:iterators are same");
    AssertEq(0, answer_0.first - someVals.begin(),"0=>[11,12,13,21,41]:insert into begin");
    const auto answer_3 = FindStartsWith(someVals.begin(), someVals.end(), '3');
    AssertTrue(answer_3.first == answer_3.second ,"3=>[11,12,13,21,41]:iterators are same");
    AssertEq("41", *answer_3.first, "3=>[11,12,13,21,41]:insert before 41");
    
    const auto answer_1 = FindStartsWith(someVals.begin(), someVals.end(), '1');
    AssertTrue(answer_1.first != answer_1.second ,"1=>[11,12,13,21,41]:iterators aren't same");
    AssertEq("11", *answer_1.first,"1=>[11,12,13,21,41]: start with 11");
    AssertEq("21", *answer_1.second,"1=>[11,12,13,21,41]: start with 21");
    
    const std::vector<std::string> sorted_strings = {"moscow", "murmansk", "vologda"};
    const auto answer_m = FindStartsWith(sorted_strings.begin(), sorted_strings.end(), 'm');
    AssertEq("moscow", *answer_m.first,"moscow == moscow");
    AssertEq("vologda", *answer_m.second,"vologda == vologda");
    
    const auto answer_p = FindStartsWith(sorted_strings.begin(), sorted_strings.end(), 'p');
    AssertTrue(answer_p.first == answer_p.second ,"p=>[moscow, murmansk, vologda]:iterators are same");
    AssertEq(2, answer_p.first - sorted_strings.begin(),"p=>[moscow, murmansk, vologda]:insert idx == 2");
    
    
    const auto answer_z = FindStartsWith(sorted_strings.begin(), sorted_strings.end(), 'z');
    AssertTrue(answer_z.first == answer_z.second ,"z=>[moscow, murmansk, vologda]:iterators are same");
    AssertEq(3, answer_z.first - sorted_strings.begin(),"p=>[moscow, murmansk, vologda]:insert idx == 3");
}

int main(int argc, const char * argv[]) {
    // insert code here...
    TestRunner r;
    r.RunTest(TestByFirstChar, "TestByFirstChar");
    r.RunTest(TestByFirstCharBorders, "TestByFirstCharBorders");
    r.RunTest(TestByFirstString, "TestByFirstString");
    r.RunTest(TestByStringBorders, "TestByFirstStringBorders");
    return 0;
}
