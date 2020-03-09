//
//  tests.hpp
//  w06-28-capstone
//
//  Created by Sergey Gordeev on 28.02.2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#ifndef tests_hpp
#define tests_hpp
#pragma once
#include <stdio.h>
#include "database.h"
#include "date.h"
#include "condition_parser.h"
#include "event_parser.hpp"
#include "node.h"
#include "token.h"
#include "test_runner.h"

void TestParseEvent() {
    {
        istringstream is("event");
        AssertEqual(ParseEvent(is), "event", "Parse event without leading spaces");
    }
    {
        istringstream is("   sport event ");
        AssertEqual(ParseEvent(is), "sport event ", "Parse event with leading spaces");
    }
    {
        istringstream is("  first event  \n  second event");
        vector<string> events;
        events.push_back(ParseEvent(is));
        events.push_back(ParseEvent(is));
        AssertEqual(events, vector<string>{"first event  ", "second event"}, "Parse multiple events");
    }
}

void TestEventCondition(){
    {
        DateComparisonNode dcn(Comparison::Equal, {10,11,12});
        Assert(dcn.Evaluate({10,11,12}, ""),"{10,11,12}  == {10,11,12}");
        Assert(!dcn.Evaluate({10,11,13}, ""),"!({10,11,13}  == {10,11,12})");
        Assert(!dcn.Evaluate({10,12,12}, ""),"!({10,12,13}  == {10,11,12})");
        Assert(!dcn.Evaluate({11,11,12}, ""),"!({11,11,13}  == {10,11,12})");
    }
    
    {
        DateComparisonNode dcn(Comparison::NotEqual, {10,11,12});
        Assert(dcn.Evaluate({9,7,8}, ""),"{9,7,8} != {10,11,12}");
        Assert(!dcn.Evaluate({10,11,12}, ""),"!({10,11,12} != {10,11,12})");
    }
    
    {
        DateComparisonNode dcn(Comparison::GreaterOrEqual, {10,11,12});
        Assert(dcn.Evaluate({10,11,12}, ""),"{10,11,12} >= {10,11,12}");
        Assert(!dcn.Evaluate({0,0,0}, ""),"!({0,0,0} >= {10,11,12})");
    }
    {
        DateComparisonNode dcn(Comparison::GreaterOrEqual, {10,11,12});
        Assert(dcn.Evaluate({10,11,13}, ""),"{10,11,13} >= {10,11,12}");
        Assert(dcn.Evaluate({10,12,12}, ""),"{10,12,12} >= {10,11,12}");
        Assert(dcn.Evaluate({11,11,12}, ""),"{11,11,12} >= {10,11,12}");
    }
    
    {
        DateComparisonNode dcn(Comparison::Greater, {10,11,12});
        Assert(!dcn.Evaluate({1,1,1}, ""),"!({1,1,1} > {10,11,12})");
        Assert(dcn.Evaluate({10,11,13}, ""),"{10,11,13} > {10,11,12}");
        Assert(dcn.Evaluate({10,12,12}, ""),"{10,12,12} > {10,11,12}");
        Assert(dcn.Evaluate({11,11,12}, ""),"{11,11,12} > {10,11,12}");
    }
    {
        DateComparisonNode dcn(Comparison::Less, {10,11,12});
        Assert(!dcn.Evaluate({12,1,1}, ""),"!({12,1,1} < {10,11,12})");
        Assert(dcn.Evaluate({10,11,11}, ""),"{10,11,11} < {10,11,12}");
        Assert(dcn.Evaluate({10,10,12}, ""),"{10,10,12} < {10,11,12}");
        Assert(dcn.Evaluate({9,11,12}, ""),"{9,11,12} < {10,11,12}");
    }
    
    {
        DateComparisonNode dcn(Comparison::LessOrEqual, {10,11,12});
        Assert(dcn.Evaluate({10,11,12}, ""),"some event <= {10,11,12}");
        Assert(dcn.Evaluate({10,11,11}, ""),"{10,11,11} <= {10,11,12}");
        Assert(dcn.Evaluate({10,10,12}, ""),"{10,10,12} <= {10,11,12}");
        Assert(dcn.Evaluate({9,11,12}, ""),"{9,11,12} <= {10,11,12}");
    }
    {
        DateComparisonNode dcn(Comparison::LessOrEqual, {10,11,12});
        Assert(dcn.Evaluate({1,1,1}, ""),"{1,1,1} <= {10,11,12}");
    }
}
void TestDateCondition(){
    {
        EventComparisonNode ecn(Comparison::Equal, "some event");
        Assert(ecn.Evaluate({0,0,0}, "some event"),"some event  == some event");
        Assert(!ecn.Evaluate({0,0,0}, "not some event"),"!(not some event  == some event)");
    }
    
    {
        EventComparisonNode ecn(Comparison::NotEqual, "some event");
        Assert(ecn.Evaluate({0,0,0}, "not some event"),"not some event != some event");
        Assert(!ecn.Evaluate({0,0,0}, "some event"),"!(some event != some event)");
    }
    
    {
        EventComparisonNode ecn(Comparison::GreaterOrEqual, "some event");
        Assert(ecn.Evaluate({0,0,0}, "some event"),"some event >= some event");
        Assert(!ecn.Evaluate({0,0,0}, "pom event"),"!(pom event >= some event)");
    }
    {
        EventComparisonNode ecn(Comparison::GreaterOrEqual, "some event");
        Assert(ecn.Evaluate({0,0,0}, "tom event"),"tom event >= some event");
    }
    
    {
        EventComparisonNode ecn(Comparison::Greater, "some event");
        Assert(!ecn.Evaluate({0,0,0}, "some event"),"!(some event > some event)");
        Assert(ecn.Evaluate({0,0,0}, "tom event"),"tom event > some event");
    }
    {
        EventComparisonNode ecn(Comparison::Less, "some event");
        Assert(!ecn.Evaluate({0,0,0}, "tom event"),"!(tom event < some event)");
        Assert(ecn.Evaluate({0,0,0}, "pom event"),"pom event < some event");
    }
    
    {
        EventComparisonNode ecn(Comparison::LessOrEqual, "some event");
        Assert(ecn.Evaluate({0,0,0}, "some event"),"some event <= some event");
        Assert(!ecn.Evaluate({0,0,0}, "tom event"),"!(tom event <= some event)");
    }
    {
        EventComparisonNode ecn(Comparison::LessOrEqual, "some event");
        Assert(ecn.Evaluate({0,0,0}, "pom event"),"pom event <= some event");
    }
}

void TestDate(){
    Date d(1,2,3);
    //hack assertation_helper  know nothing about date unit. because of that use Assert instead of AssertEq
    Assert(Year(1) == d.year, "check year");
    Assert(Month(2) ==  d.month, "check month");
    Assert(Day(3) == d.day, "check day");
    auto expected = make_tuple(Year(1),Month(2),Day(3));
    Assert(expected == d.asTuple(), "asTuple");
    stringstream ss;
    ss << d;
    string dateString = ss.str();
    AssertEqual("0001-02-03", dateString, "check <<");
    istringstream iss(dateString);
    Date parsedDate =  ParseDate(iss);
    Assert(d == parsedDate, "check ParseDate");
}
void TestAdd(){
    Database d;
    Date date111(1,1,1);
    d.Add(date111, "event_1");
    vector<pair<Date,string>> result = d.All();
    
    AssertEqual(1, result.size(), "check size for single evt");
    Assert(date111 == result.front().first, "check date for single event");
    AssertEqual("event_1", result.front().second, "check event_1 for single evt");
    
    d.Add(date111, "event_1");
    d.Add(date111, "event_2");
    d.Add(date111, "event_1");
    
    result = d.All();
    AssertEqual(2, result.size(), "check size for 2 events");
    
    Assert(date111 == result.front().first, "check date for single event");
    AssertEqual("event_1", result.front().second, "check event_1 for single evt");
    
    Assert(date111 == result.back().first, "check date for single event");
    AssertEqual("event_2", result.back().second, "check event_1 for single evt");
    
    Date date222(2,2,2);
    d.Add(date222, "event_1");
    d.Add(date222, "event_1");
    d.Add(date222, "event_2");
    d.Add(date222, "event_1");
    
    result = d.All();
    AssertEqual(4, result.size(), "check size for single evt");
    
    std::pair<Date,string> p0 = make_pair(date111,"event_1");
    Assert(p0 == result[0], "{1,1,1} event_1");
    
    std::pair<Date,string> p1 = make_pair(date111,"event_2");
    Assert(p1 == result[1], "{1,1,1} event_2");
    
    
    std::pair<Date,string> p2 = make_pair(date222,"event_1");
    Assert(p2 == result[2], "{2,2,2} event_1");
    
    std::pair<Date,string> p3 = make_pair(date222,"event_2");
    Assert(p3== result[3], "{2,2,2} event_2");
    
}
void TestFindIf(){
    Database db;
    auto any = [](const Date& d, const std::string& s){return true;};
    AssertEqual(0, db.FindIf(any).size(), "empty db");
    
    db. Add({1,1,1}, "event_1");
    AssertEqual(1, db.FindIf(any).size(), "one element");
    Assert(db.All() == db.FindIf(any), "chek is same with all");
    auto res1 = db.FindIf(any);
    res1[0].second = "event_1_modifyed";
    res1[0].first = {10,10,10};
    Assert(res1[0].first != db.FindIf(any)[0].first, "check is changing  result affect db row: Date");
    Assert(res1[0].second != db.FindIf(any)[0].second, "check is changing  result affect db row: Event");
    
    db.Add({1,1,1}, "event_1");
    db.Add({1,1,1}, "event_2");
    db.Add({2,2,2}, "event_1");
    db.Add({2,2,2}, "event_2");
    AssertEqual(4, db.FindIf(any).size(), "for element");
    Assert(db.All() == db.FindIf(any), "chek is same with all for 4 elements");
    
    auto eventtsAt222 = db.FindIf([](const Date& d, const string& s){
        return d == Date(2,2,2);
    });
    AssertEqual(2, eventtsAt222.size(), "search for all event at {2,2,2}");
    Assert(Date(2,2,2) == eventtsAt222[0].first, "check is [0] date eq {2,2,2}");
    Assert(Date(2,2,2) == eventtsAt222[1].first, "check is [1] date eq {2,2,2}");
    Assert(eventtsAt222[0] != eventtsAt222[1], "check are both element different(eventtsAt222)");
    
    auto eventtsAtEvt1 = db.FindIf([](const Date& d, const string& s){
        return s == "event_1";
    });
    AssertEqual(2, eventtsAtEvt1.size(), "search for all event_1");
    Assert("event_1" == eventtsAtEvt1[0].second, "check is [0] date eq event_1");
    Assert("event_1" == eventtsAtEvt1[1].second, "check is [1] date eq event_1");
    Assert(eventtsAt222[0] != eventtsAt222[1], "check are both element different(eventtsAtEvt1)");
    
    db.Add({1,1,1}, "action_1");
    auto checkStable = db.FindIf([](const Date& d, const string& s){
        return d == Date(1,1,1);
    });
    
    Assert("event_1" == checkStable[0].second, "check is [0] date eq event_1");
    Assert("event_2" == checkStable[1].second, "check is [1] date eq event_2");
    Assert("action_1" == checkStable[2].second, "check is [12] date eq action_1");
    auto evt_1111 = db.FindIf([](const Date& d, const string& s){
        return s == "event_1111";
    });
    AssertEqual(0, evt_1111.size(), "search for all event event_1111");
}
void TestPrint(){
    ostringstream expected;
    expected << "2017-01-01 Holiday\n";
    expected << "2017-01-01 New Year\n";
    expected << "2017-03-08 Holiday\n";
    Database db;
    db.Add({2017,1,1}, "Holiday");
    db.Add({2017,3,8}, "Holiday");
    db.Add({2017,1,1}, "New Year");
    db.Add({2017,1,1}, "New Year");
    ostringstream actual;
    db.Print(actual);
    AssertEqual(expected.str(), actual.str(), "check print");
}
void TestLast(){
    Database db;
    db.Add({3,3,3}, "event_333_1");
    db.Add({3,3,3}, "event_333_2");
    db.Add({2,2,2}, "event_222_1");
    db.Add({2,2,2}, "event_222_2");
    try{
        db.Last({1,1,1});
        Assert(false,"nothing found failed");
    }catch(const invalid_argument&){
        Assert(true,"nothing found");
    }
    
    AssertEqual("event_222_2", db.Last({2,2,2}).second, "last for {2, 2, 2}");
    AssertEqual("event_333_2", db.Last({4,4,4}).second, "last for {4, 4, 4}");
}
void TestDel(){
    
    auto all = [](const Date& d, const string& s){
        return true;
    };
    Database db;
    
    int count = db.RemoveIf(all);
    AssertEqual(0,count, "remove all from empty db");
    
    db.Add({3,3,3}, "event_333_1");
    db.Add({3,3,3}, "event_333_2");
    db.Add({2,2,2}, "event_222_1");
    db.Add({2,2,2}, "event_222_2");
    count = db.RemoveIf(all);
    AssertEqual(4,count, "remove all");
    AssertEqual(0, db.FindIf(all).size(), "check if anything left in db");
    
    
    db.Add({3,3,3}, "event_333_1");
    db.Add({3,3,3}, "event_333_2");
    db.Add({2,2,2}, "event_222_1");
    db.Add({2,2,2}, "event_222_2");
    DateComparisonNode condition(Comparison::Greater,{2,2,2});
    auto late222 = [condition](const Date& d, std::string& s){
        return condition.Evaluate(d, s);
    };
    count = db.RemoveIf(late222);
    AssertEqual(2, count, "remove all date later than {2,2,2}");
    AssertEqual(0, db.FindIf(late222).size(), "find all date later than {2,2,2}");
}

#endif /* tests_hpp */
