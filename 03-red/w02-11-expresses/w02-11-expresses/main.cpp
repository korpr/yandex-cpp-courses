#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <string>
#include <set>
#include "test_runner.h"
//#include "profiler.h"

using namespace std;

class RouteManager {
public:
    void AddRoute(int start, int finish) {
        reachable_lists_[start].insert(finish);
        reachable_lists_[finish].insert(start);
    }
    int FindNearestFinish(int start, int finish) const {
        
        int result = abs(start - finish);
        if (reachable_lists_.count(start) < 1) {
            return result;
        }
        const set<int>& reachable_stations = reachable_lists_.at(start);
        const auto target = reachable_stations.lower_bound(finish);
        if (target != end(reachable_stations)) {
            result = min(result, abs(finish - *target));
        }
        if (target != begin(reachable_stations)) {
            result = min(result, abs(finish - *prev(target)));
        }
        return result;
        
        return result;
    }
private:
    map<int, set<int>> reachable_lists_;
};
/*
 void TestSolution(){
 RouteManager rm;
 rm.AddRoute( -2 ,5);
 rm.AddRoute( 10, 4);
 rm.AddRoute( 5, 8);
 ASSERT_EQUAL(0,rm.FindNearestFinish( 4, 10));
 ASSERT_EQUAL(6,rm.FindNearestFinish( 4, -2));
 ASSERT_EQUAL(2,rm.FindNearestFinish( 5, 0));
 ASSERT_EQUAL(2,rm.FindNearestFinish( 5, -4));
 ASSERT_EQUAL(0,rm.FindNearestFinish( 5, -2));
 ASSERT_EQUAL(92,rm.FindNearestFinish( 5, 100));
 }
 void TestPerform(){
 RouteManager rm;
 {
 LOG_DURATION("INSERT")
 for (size_t idx = 0;idx < 100'000;++idx){
 rm.AddRoute(1000000000 - rand() % 2000000000, 1000000000 - rand() % 2000000000);
 }
 }
 {
 LOG_DURATION("FULL")
 for (size_t idx = 0;idx < 100'000;++idx){
 {
 //LOG_DURATION("ITERATION")
 rm.FindNearestFinish(1000000000 - rand() % 2000000000, 1000000000 - rand() % 2000000000);
 }
 }
 }
 }
 */
int main() {
    // TestRunner tr;
    // RUN_TEST(tr, TestSolution);
    // RUN_TEST(tr, TestPerform);
    RouteManager routes;
    
    int query_count;
    cin >> query_count;
    
    for (int query_id = 0; query_id < query_count; ++query_id) {
        string query_type;
        cin >> query_type;
        int start, finish;
        cin >> start >> finish;
        if (query_type == "ADD") {
            routes.AddRoute(start, finish);
        } else if (query_type == "GO") {
            cout << routes.FindNearestFinish(start, finish) << "\n";
        }
    }
    
    return 0;
}
