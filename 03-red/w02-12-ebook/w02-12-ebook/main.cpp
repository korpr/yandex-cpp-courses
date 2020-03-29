#include <iomanip>
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include "test_runner.h"


using namespace std;

class ReadingManager {
public:
    ReadingManager()
    : pages_rates_(MAX_PAGE_COUNT_ + 1),
    users_pages_()
    {}
    

    
    void Read(int user_id, int page_count) {
        
        if (page_count){
            pages_rates_[users_pages_[user_id]].erase(user_id);
            pages_rates_[page_count].insert(user_id);
            users_pages_[user_id] = page_count;
        }
    }
    
    double Cheer(int user_id) const {
        if (users_pages_.count(user_id) == 0) {
            return 0;
        }
        const int user_count = users_pages_.size();
        if (user_count == 1) {
            return 1;
        }
        
        double count = 0;
        
        for(int idx = users_pages_.at(user_id) - 1; idx > 0;--idx){
            count += pages_rates_[idx].size();
        }
        // По умолчанию деление целочисленное, поэтому
        // нужно привести числитель к типу double.
        // Простой способ сделать это — умножить его на 1.0.
        
        return   count / (user_count - 1);
    }
    
private:
    // Статическое поле не принадлежит какому-то конкретному
    // объекту класса. По сути это глобальная переменная,
    // в данном случае константная.
    // Будь она публичной, к ней можно было бы обратиться снаружи
    // следующим образом: ReadingManager::MAX_USER_COUNT.
    static const int MAX_PAGE_COUNT_ = 1'000;
    
    vector<set<int>> pages_rates_;
    map<int, int> users_pages_;
};


void TestSolution(){
    ReadingManager rm;
    ASSERT_EQUAL(0,rm.Cheer(5));
    rm.Read(1, 10);
    ASSERT_EQUAL(1, rm.Cheer(1));
    rm.Read( 2, 5);
    rm.Read( 3, 7);
    ASSERT_EQUAL(0, rm.Cheer(2));
    ASSERT_EQUAL(0.5, rm.Cheer(3));
    rm.Read( 3, 10);
    ASSERT_EQUAL(0.5, rm.Cheer(3));
    rm.Read( 3, 11);
    ASSERT_EQUAL(1, rm.Cheer(3));
    ASSERT_EQUAL(0.5, rm.Cheer(1));
}
void TestPerform(){
    ReadingManager rm;
    {
        LOG_DURATION("INSERT")
        for (size_t idx = 0;idx < 100'000'0 * 0.5;++idx){
            rm.Read(rand() % 100'000, rand() % 1000 + 1);
        }
    }
    {
        LOG_DURATION("FULL")
        for (size_t idx = 0;idx < 100'000'0 * 0.5;++idx){
            rm.Cheer(rand() % 100'000);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    TestRunner tr;
    RUN_TEST(tr, TestSolution);
    RUN_TEST(tr, TestPerform);
    
    ReadingManager manager;
    
    int query_count;
    cin >> query_count;
    
    for (int query_id = 0; query_id < query_count; ++query_id) {
        string query_type;
        cin >> query_type;
        int user_id;
        cin >> user_id;
        
        if (query_type == "READ") {
            int page_count;
            cin >> page_count;
            manager.Read(user_id, page_count);
        } else if (query_type == "CHEER") {
            cout << setprecision(6) << manager.Cheer(user_id) << "\n";
        }
    }
    
    return 0;
}
