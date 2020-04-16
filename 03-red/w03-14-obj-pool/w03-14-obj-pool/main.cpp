#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>
using namespace std;

template <class T>
class ObjectPool {
public:
    T* Allocate(){
        if (pool.empty()){
            auto element = new T;
            allocated.push_back(element);
            
            return element;
        }else{
            auto element = pool.front();
            allocated.push_back(element);
            pool.pop_front();
            return element;
        }
    }
    T* TryAllocate(){
        if (pool.empty()){
            return nullptr;
        }else{
            auto element = pool.front();
            allocated.push_back(element);
            pool.pop_front();
            return element;
        }
    }
    
    void Deallocate(T* object){
        auto it = find(begin(allocated), end(allocated),object);
        if (it == end(allocated)){
            throw invalid_argument("");
        }
        pool.push_back(*it);
        allocated.erase(it);
    }
    
    ~ObjectPool(){
        for (const auto element: allocated){
            delete element;
        }
        allocated.clear();
        while(!pool.empty()){
            delete pool.back();
            pool.pop_back();
        }
    }
    
private:
    vector<T*> allocated;
    deque<T*> pool;
};
void TestObjectPoolMemLick() {
    {
        ObjectPool<string> pool;
        for (size_t i = 0; i  < 10000000;++i){
            auto el = pool.Allocate();
            *el = to_string(i);
        }
    }
}
void TestObjectPool() {
    ObjectPool<string> pool;
    
    auto p1 = pool.Allocate();
    auto p2 = pool.Allocate();
    auto p3 = pool.Allocate();
    
    *p1 = "first";
    *p2 = "second";
    *p3 = "third";
    
    pool.Deallocate(p2);
    ASSERT_EQUAL(*pool.Allocate(), "second");
    
    pool.Deallocate(p3);
    pool.Deallocate(p1);
    ASSERT_EQUAL(*pool.Allocate(), "third");
    ASSERT_EQUAL(*pool.Allocate(), "first");
    
    pool.Deallocate(p1);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestObjectPool);
    RUN_TEST(tr, TestObjectPoolMemLick);
    return 0;
}
