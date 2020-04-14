//
//  main.cpp
//  w02-13-booking
//
//  Created by Sergey Gordeev on 30.03.2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <deque>
#include "test_runner.h"

using namespace std;

const int64_t REQEST_VALIDITY_SEC = 86'400;

struct Order{
    Order(int64_t time, size_t client_id, size_t room_count):
    time(time),
    client_id(client_id),
    room_count(room_count){}
    int64_t time;
    size_t client_id;
    size_t room_count;
};

class Hotel{
public:
    Hotel():room_count_(0),orders_(){};
    void new_order(int64_t& time, string& hotel_name, size_t& client_id, size_t& room_count){
        client_time_[client_id] = time;
        room_count_ += room_count;
        orders_.push_back({time, client_id, room_count});
        trim(time - REQEST_VALIDITY_SEC);
    }
    
    uint64_t Clients(int64_t system_last_orrder) {
        trim(system_last_orrder);
        return client_time_.size();
    }
    
    uint64_t Rooms(int64_t system_last_orrder) {
        trim(system_last_orrder);
        return room_count_;
    }

private:
    void trim(int64_t last_order){
    
        while(!orders_.empty() && orders_.front().time <= last_order)
        {
            const Order& ord = orders_.front();
            room_count_ -= ord.room_count;
            orders_.pop_front();
            if (client_time_[ord.client_id] <= last_order){
                client_time_.erase(ord.client_id);
            }
        }
    }
    
    int64_t room_count_;
    deque<Order> orders_;
    map<int64_t,int64_t> client_time_;
    
};


class BookingManager{
public:
    BookingManager(): day(numeric_limits<int64_t>::min()){};
    uint64_t Clients(const string& hotel) {
        return hotels[hotel].Clients(day);
    }
    uint64_t Rooms(const string& hotel) {
        
        return hotels[hotel].Rooms(day);
    }
    void Book(int64_t time, string hotel_name, size_t client_id, size_t room_count){
        day = time - REQEST_VALIDITY_SEC;
        hotels[hotel_name].new_order(time, hotel_name, client_id, room_count);
    }
private:
    int64_t day;
    map<string, Hotel> hotels;
};

void TestSolution(){
    BookingManager bm;
    ASSERT_EQUAL(0 ,bm.Clients("Marriott"))
    ASSERT_EQUAL(0 ,bm.Rooms("Marriott"))
    bm.Book(10, "FourSeasons", 1, 2);
    bm.Book(10, "Marriott", 1, 1);
    bm.Book(REQEST_VALIDITY_SEC +9, "FourSeasons", 2, 1);
    ASSERT_EQUAL(2, bm.Clients("FourSeasons"))
    ASSERT_EQUAL(3, bm.Rooms("FourSeasons"))
    ASSERT_EQUAL(1, bm.Clients("Marriott"))
    bm.Book(REQEST_VALIDITY_SEC +10, "Marriott", 2, 10);
    ASSERT_EQUAL(1, bm.Rooms("FourSeasons"))
    ASSERT_EQUAL(10, bm.Rooms("Marriott"))
    
}


void TestSolution2(){
    {
        BookingManager bm;
        ASSERT_EQUAL(0, bm.Clients("1"))
        bm.Book(0, "2", 2, 2);
        ASSERT_EQUAL(0, bm.Clients("1"))
        bm.Book(0, "1", 1, 1);
        ASSERT_EQUAL(1, bm.Clients("1"))
        bm.Book(REQEST_VALIDITY_SEC, "2", 2, 2);
        ASSERT_EQUAL(0, bm.Clients("1"))
        ASSERT_EQUAL(1, bm.Clients("2"))
    }
    {
        BookingManager bm;
        ASSERT_EQUAL(0, bm.Clients("1"))
        bm.Book(0, "1", 1, 1);
        ASSERT_EQUAL(1, bm.Clients("1"))
        bm.Book(0, "1", 1, 1);
        ASSERT_EQUAL(1, bm.Clients("1"))
        bm.Book(REQEST_VALIDITY_SEC, "1", 1, 1);
        ASSERT_EQUAL(1, bm.Clients("1"))
    }
    {
        BookingManager bm;
        bm.Book(0, "1", 1, 1);
        bm.Book(1, "1", 12, 1);
        bm.Book(1, "1", 13, 1);
        bm.Book(1, "1", 1, 1);
        bm.Book(1, "1", 1, 1);
        ASSERT_EQUAL(3, bm.Clients("1"))
        bm.Book(REQEST_VALIDITY_SEC, "1", 14, 1);
        ASSERT_EQUAL(4, bm.Clients("1"))
    }
    {
        BookingManager bm;
        bm.Book(0, "1", 1, 1);
        bm.Book(1, "1", 12, 1);
        bm.Book(1, "1", 13, 1);
        bm.Book(1, "1", 1, 1);
        bm.Book(1, "1", 1, 1);
        ASSERT_EQUAL(3, bm.Clients("1"))
        bm.Book(REQEST_VALIDITY_SEC, "12", 1, 1);
        ASSERT_EQUAL(3, bm.Clients("1"))
        ASSERT_EQUAL(1, bm.Clients("12"))
    }
    {
        BookingManager bm;
        bm.Book(0, "1", 1, 1);
        bm.Book(1, "1", 12, 1);
        bm.Book(1, "1", 13, 1);
        bm.Book(1, "1", 14, 1);
        bm.Book(1, "1", 15, 1);
        ASSERT_EQUAL(5, bm.Clients("1"))
        bm.Book(REQEST_VALIDITY_SEC, "1", 16, 1);
        ASSERT_EQUAL(5, bm.Clients("1"))
    }
}


void TestSolution3(){
    {
        BookingManager bm;
        bm.Book(0, "q", 0, 1 );
        ASSERT_EQUAL(bm.Clients("q"), 1);
        ASSERT_EQUAL(bm.Rooms("q"), 1);
        bm.Book(10, "q", 0, 3);
        ASSERT_EQUAL(bm.Clients("q"), 1);
        ASSERT_EQUAL(bm.Rooms("q"), 4);
        bm.Book( 86411, "q", 3, 1 );
        ASSERT_EQUAL(bm.Clients("q"), 1);
        ASSERT_EQUAL(bm.Rooms("q"), 1);
    }
    {
        BookingManager bm;
        bm.Book( 0, "hotel", 1, 1);
        bm.Book( 86500, "hotel2", 1, 1);
        ASSERT_EQUAL(0, bm.Clients("hotel"))
        
    }
    {
        BookingManager bm;
        bm.Book( -86400, "hotel", 2, 2);
        bm.Book( 0, "hotel", 1, 5);
        ASSERT_EQUAL(1, bm.Clients("hotel"))
        ASSERT_EQUAL(5, bm.Rooms("hotel"))
    }
    {
        BookingManager bm;
        bm.Book( 0, "FourSeasons", pow(10 ,9), 1000);
        bm.Book(0, "FourSeasons", 1, 3);
        bm.Book(0, "FourSeasons", 2, 3);
        bm.Book(0, "FourSeasons", 2, 3);
        bm.Book(0, "FourSeasons", 1, 3);
        bm.Book( 0, "FourSeasons", pow(10 ,9), 1000);
        
        ASSERT_EQUAL(3, bm.Clients("FourSeasons"))
    }
    {
        BookingManager bm;
        bm.Book( 0, "FourSeasons", pow(10 ,9), 1000);
        bm.Book(REQEST_VALIDITY_SEC, "FourSeasons", 1, 3);
        
        ASSERT_EQUAL(3, bm.Rooms("FourSeasons"))
        ASSERT_EQUAL(1, bm.Clients("FourSeasons"))
    }
    {
        BookingManager bm;
        bm.Book( 1, "FourSeasons", pow(10 ,9), 1000);
        bm.Book( REQEST_VALIDITY_SEC, "FourSeasons", 1, 3);
        
        ASSERT_EQUAL(1003, bm.Rooms("FourSeasons"))
        ASSERT_EQUAL(2, bm.Clients("FourSeasons"))
    }
    {
        BookingManager bm;
        bm.Book( 0, "FourSeasons", pow(10 ,9), 1000);
        bm.Book( REQEST_VALIDITY_SEC +1, "FourSeasons", 1, 3);
        bm.Book( 2*REQEST_VALIDITY_SEC +2, "FourSeasons", 2, 4);
        bm.Book( 3*REQEST_VALIDITY_SEC +3, "FourSeasons", 1, 5);
        ASSERT_EQUAL(5, bm.Rooms("FourSeasons"))
        ASSERT_EQUAL(1, bm.Clients("FourSeasons"))
        
    }
    {
        BookingManager bm;
        bm.Book( 0, "FourSeasons", pow(10 ,9), 1000);
        bm.Book( 0, "FourSeasons", 1, 1000);
        ASSERT_EQUAL(2000, bm.Rooms("FourSeasons"))
        ASSERT_EQUAL(2, bm.Clients("FourSeasons"))
        
    }
    {
        BookingManager bm;
        bm.Book( 0, "FourSeasons", 1, 1000);
        bm.Book( 0, "FourSeasons", 1, 1000);
        ASSERT_EQUAL(2000, bm.Rooms("FourSeasons"))
        ASSERT_EQUAL(1, bm.Clients("FourSeasons"))
        
    }
    {
        BookingManager bm;
        bm.Book( 0, "FourSeasons", pow(10 ,9), 1000);
        bm.Book( 0, "FourSeasons", 1, 1000);
        ASSERT_EQUAL(2000, bm.Rooms("FourSeasons"))
        ASSERT_EQUAL(2, bm.Clients("FourSeasons"))
        
    }
    {
        BookingManager bm;
        bm.Book( 0, "FourSeasons", pow(10 ,9), 1000);
        bm.Book( 0, "FourSeasons1", pow(10 ,9), 1000);
        ASSERT_EQUAL(1000, bm.Rooms("FourSeasons"))
        ASSERT_EQUAL(1, bm.Clients("FourSeasons"))
        ASSERT_EQUAL(1000, bm.Rooms("FourSeasons1"))
        ASSERT_EQUAL(1, bm.Clients("FourSeasons1"))
    }
    {
        BookingManager bm;
        bm.Book( 0, "FourSeasons", pow(10 ,9), 1000);
        ASSERT_EQUAL(1000, bm.Rooms("FourSeasons"))
        ASSERT_EQUAL(1, bm.Clients("FourSeasons"))
        bm.Book( 86'401, "FourSeasons", 4, 3);
        ASSERT_EQUAL(3, bm.Rooms("FourSeasons"))
        ASSERT_EQUAL(1, bm.Clients("FourSeasons"))
    }
    {
        BookingManager bm;
        bm.Book( 0, "FourSeasons", pow(10 ,9), 1000);
        ASSERT_EQUAL(1000, bm.Rooms("FourSeasons"))
        ASSERT_EQUAL(1, bm.Clients("FourSeasons"))
        bm.Book( 86'401, "FourSeasons1", pow(10 ,9), 1000);
        ASSERT_EQUAL(0, bm.Rooms("FourSeasons"))
        ASSERT_EQUAL(0, bm.Clients("FourSeasons"))
        ASSERT_EQUAL(1000, bm.Rooms("FourSeasons1"))
        ASSERT_EQUAL(1, bm.Clients("FourSeasons1"))
    }
    {
        BookingManager bm;
        ASSERT_EQUAL(0, bm.Rooms("FourSeasons"))
        ASSERT_EQUAL(0, bm.Clients("FourSeasons"))
    }
    {
        BookingManager bm;
        bm.Book( 0, "FourSeasons", pow(10 ,9), 1000);
        ASSERT_EQUAL(1000, bm.Rooms("FourSeasons"))
        ASSERT_EQUAL(1, bm.Clients("FourSeasons"))
    }
    {
        BookingManager bm;
        bm.Book( 0, "FourSeasons", pow(10 ,9), 1000);
        bm.Book( 1, "FourSeasons", pow(10 ,9), 1000);
        bm.Book( 2, "FourSeasons", pow(10 ,9), 1000);
        ASSERT_EQUAL(3000, bm.Rooms("FourSeasons"))
        ASSERT_EQUAL(1, bm.Clients("FourSeasons"))
        bm.Book( 84'6003, "FourSeasons", pow(10 ,9), 1);
        ASSERT_EQUAL(1, bm.Rooms("FourSeasons"))
        ASSERT_EQUAL(1, bm.Clients("FourSeasons"))
    }
    {
        BookingManager bm;
        bm.Book( 0, "FourSeasons", pow(10 ,9), 1000);
        bm.Book( 1, "FourSeasons", pow(10 ,9), 1000);
        bm.Book( 2, "FourSeasons", pow(10 ,9), 1000);
        ASSERT_EQUAL(3000, bm.Rooms("FourSeasons"))
        ASSERT_EQUAL(1, bm.Clients("FourSeasons"))
        bm.Book( 84'6003, "FourSeasons", 1, 19);
        ASSERT_EQUAL(19, bm.Rooms("FourSeasons"))
        ASSERT_EQUAL(1, bm.Clients("FourSeasons"))
    }
    
    {
        BookingManager bm;
        bm.Book( 3, "FourSeasons", 1, 1);
        bm.Book( 3, "FourSeasons", 2, 1);
        bm.Book( 3, "FourSeasons", 3, 1);
        ASSERT_EQUAL(3, bm.Rooms("FourSeasons"))
        ASSERT_EQUAL(3, bm.Clients("FourSeasons"))
    }
    
    {
        BookingManager bm;
        bm.Book( 3, "FourSeasons", 1, 1);
        bm.Book( 3, "FourSeasons1", 2, 1);
        bm.Book( 3, "FourSeasons2", 3, 1);
        ASSERT_EQUAL(1, bm.Rooms("FourSeasons"))
        ASSERT_EQUAL(1, bm.Clients("FourSeasons"))
    }
    {
        BookingManager bm;
        bm.Book( 3, "FourSeasons", 1, 1);
        bm.Book( 3, "FourSeasons1", 2, 1);
        bm.Book( REQEST_VALIDITY_SEC +4, "FourSeasons2", 3, 1);
        ASSERT_EQUAL(0, bm.Rooms("FourSeasons"))
        ASSERT_EQUAL(0, bm.Clients("FourSeasons"))
        ASSERT_EQUAL(1, bm.Rooms("FourSeasons2"))
        ASSERT_EQUAL(1, bm.Clients("FourSeasons2"))
    }
}

void TestPerformance(){
    
    size_t user_id_limit =  pow(10 ,9);
    BookingManager bm;
    
    {
        LOG_DURATION("INSERT")
        for(int idx = 0; idx < 10'000'0;++idx ){
            unsigned long time = idx;
            unsigned long user = rand() % user_id_limit;
            int room = rand() % 1000;
            bm.Book(
                    time,
                    to_string( idx % 300),
                    user,
                    room);
            
        }
    }
    
    {
        LOG_DURATION("ROOMS")
        for(int idx = 0; idx < 10'000'0;++idx ){
            bm.Rooms(to_string( idx % 200));
        }
    }
    
    {
        LOG_DURATION("CLIENTS")
        for(int idx = 0; idx < 10'000'0;++idx ){
            string name = to_string( idx % 300);
            bm.Clients(to_string( idx % 200));
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    {
        TestRunner tr;
        RUN_TEST(tr, TestSolution);
        RUN_TEST(tr, TestSolution2);
        RUN_TEST(tr, TestSolution3);
        RUN_TEST(tr, TestPerformance);
    }
    
    BookingManager manager;
    
    int query_count;
    cin >> query_count;
    
    for (int query_id = 0; query_id < query_count; ++query_id) {
        string query_type;
        cin >> query_type;
        
        if (query_type == "BOOK") {
            int64_t time;
            string hotel;
            size_t user_id, rooms;
            cin >> time >> hotel >> user_id >> rooms;
            manager.Book(time, hotel, user_id, rooms);
        } else if (query_type == "CLIENTS") {
            string hotel;
            cin >> hotel;
            cout << manager.Clients(hotel) << "\n";
        }else if (query_type == "ROOMS") {
            string hotel;
            cin >> hotel;
            cout << manager.Rooms(hotel) << "\n";
        }
    }
    return 0;
}
