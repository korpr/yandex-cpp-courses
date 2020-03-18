//
//  main.cpp
//  w01-07-deque
//
//  Created by Sergey Gordeev on 17.03.2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#include <iostream>
#include "test_runner.h"
#include "dec.hpp"

void TestPushForward(){
    Deque<int> dq;
    dq.PushFront(1);
    ASSERT_EQUAL(1 ,dq.Front());
    dq.PushFront(2);
    ASSERT_EQUAL(2 ,dq.Front());
}
void TestForward(){
    Deque<int> dq;
    dq.PushBack(10);
    ASSERT_EQUAL(10,dq.Front());
    dq.PushFront(1);
    ASSERT_EQUAL(1 ,dq.Front());
    dq.PushFront(2);
    ASSERT_EQUAL(2 ,dq.Front());
}
void TestPushBack(){
    Deque<int> dq;
    dq.PushBack(1);
    ASSERT_EQUAL(1 ,dq.Back());
    dq.PushBack(2);
    ASSERT_EQUAL(2 ,dq.Back());
}
void TestBack(){
    Deque<int> dq;
    dq.PushFront(10);
    ASSERT_EQUAL(10 ,dq.Back());
    dq.PushBack(1);
    ASSERT_EQUAL(1 ,dq.Back());
    dq.PushBack(2);
    ASSERT_EQUAL(2 ,dq.Back());
}
void TestAt(){
    try{
        Deque<int> dq;
        dq.At(0);
        ASSERT(false);
    }catch(const out_of_range& e){
        ASSERT(true);
    }
    {
        Deque<int> dq;
        dq.PushBack(2);
        ASSERT_EQUAL(2, dq.At(0));
        dq.PushFront(1);
        ASSERT_EQUAL(1, dq.At(0));
        ASSERT_EQUAL(2, dq.At(1));
    }
    {
        Deque<int> dq;
        dq.PushFront(2);
        dq.PushFront(1);
        ASSERT_EQUAL(1, dq.At(0));
        ASSERT_EQUAL(2, dq.At(1));
    }
    {
        Deque<int> dq;
        dq.PushBack(1);
        dq.PushBack(2);
        ASSERT_EQUAL(1, dq.At(0));
        ASSERT_EQUAL(2, dq.At(1));
    }
}
void TestGet(){
    try{
        Deque<int> dq;
        dq[0];
        ASSERT(true);
    }catch(const out_of_range& e){
        ASSERT(false);
    }
    {
        Deque<int> dq;
        dq.PushBack(2);
        ASSERT_EQUAL(2, dq[0]);
        dq.PushFront(1);
        ASSERT_EQUAL(1, dq[0]);
        ASSERT_EQUAL(2, dq[1]);
    }
    {
        Deque<int> dq;
        dq.PushFront(2);
        dq.PushFront(1);
        ASSERT_EQUAL(1, dq[0]);
        ASSERT_EQUAL(2, dq[1]);
    }
    {
        Deque<int> dq;
        dq.PushBack(1);
        dq.PushBack(2);
        ASSERT_EQUAL(1, dq.At(0));
        ASSERT_EQUAL(2, dq.At(1));
    }
}

void TestSize(){
    Deque<int> dq;
    ASSERT_EQUAL(0,dq.Size());
    dq.PushBack(1);
    ASSERT_EQUAL(1,dq.Size());
    dq.PushFront(1);
    ASSERT_EQUAL(2,dq.Size());
}

void TestEmpty(){
    {
        Deque<int> dq;
        ASSERT(dq.Empty());
    }
    {
        Deque<int> dq;
        dq.PushBack(1);
        ASSERT(!dq.Empty());
        
    }
    {
        Deque<int> dq;
        dq.PushFront(1);
        ASSERT(!dq.Empty());
    }
}
int main(int argc, const char * argv[]) {
    TestRunner tr;
    RUN_TEST(tr, TestPushForward);
    RUN_TEST(tr, TestForward);
    RUN_TEST(tr, TestPushBack);
    RUN_TEST(tr, TestBack);
    RUN_TEST(tr, TestGet);
    RUN_TEST(tr, TestAt);
    RUN_TEST(tr, TestSize);
    RUN_TEST(tr, TestEmpty);
    return 0;
}
