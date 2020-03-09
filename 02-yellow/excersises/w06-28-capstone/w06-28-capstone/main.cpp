#include "database.h"
#include "date.h"
#include "condition_parser.h"
#include "event_parser.hpp"
#include "node.h"
#include "token.h"
#include "test_runner.h"

#include <iostream>
#include <stdexcept>
#include <algorithm>

#include "tests.hpp"
using namespace std;

void TestAll();

int main() {
    TestAll();
    
    Database db;
    
    for (string line; getline(cin, line); ) {
        istringstream is(line);
        
        string command;
        is >> command;
        if (command == "Add") {
            const auto date = ParseDate(is);
            const auto event = ParseEvent(is);
            db.Add(date, event);
        } else if (command == "Print") {
            db.Print(cout);
        } else if (command == "Del") {
            auto condition = ParseCondition(is);
            auto predicate = [condition](const Date& date, const string& event) {
                return condition->Evaluate(date, event);//duplicate??lambda
            };
            int count = db.RemoveIf(predicate);
            cout << "Removed " << count << " entries" << endl;
        } else if (command == "Find") {
            auto condition = ParseCondition(is);
            auto predicate = [condition](const Date& date, const string& event) {
                return condition->Evaluate(date, event);
            };
            
            const auto entries = db.FindIf(predicate);
            for (const auto& entry : entries) {
                cout << entry << endl;
            }
            cout << "Found " << entries.size() << " entries" << endl;
        } else if (command == "Last") {
            try {
                cout << db.Last(ParseDate(is)) << endl;
            } catch (invalid_argument&) {
                cout << "No entries" << endl;
            }
        } else if (command.empty()) {
            continue;
        } else {
            throw logic_error("Unknown command: " + command);
        }
    }
    
    return 0;
}


void TestAll() {
    TestRunner tr;
    tr.RunTest(TestDel, "TestDel");
    tr.RunTest(TestLast, "TestLast");
    tr.RunTest(TestPrint, "TestPrint");
    tr.RunTest(TestFindIf, "TestFindIf");
    tr.RunTest(TestAdd, "TestAdd");
    tr.RunTest(TestDate, "TestDate");
    tr.RunTest(TestDateCondition, "TestDateCondition");
    tr.RunTest(TestEventCondition, "TestEventCondition");
    tr.RunTest(TestParseEvent, "TestParseEvent");
    tr.RunTest(TestParseCondition, "TestParseCondition");
}
