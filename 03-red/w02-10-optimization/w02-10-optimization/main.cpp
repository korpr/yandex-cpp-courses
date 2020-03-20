//
//  main.cpp
//  w02-10-optimization
//
//  Created by Sergey Gordeev on 20.03.2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "test_runner.h"
#include "profiler.h"
#include "learner.cpp"

void TestPerform(){
    Learner learner;
    for (size_t i = 0 ; i < 100; ++i){
        size_t words_count = rand() % 10000;
        vector<string> words;
        for (size_t y = 0; y < words_count;++y){
            string word = to_string(rand() % 1000);
            words.push_back(word);
        }
        {
            LOG_DURATION("LERN")
            learner.Learn(words);
        }
    }
    {
        LOG_DURATION("KnownWords")
        learner.KnownWords();
    }
}
int main() {
    TestRunner tr;
    RUN_TEST(tr,TestPerform);
    Learner learner;
    string line;
    while (getline(cin, line)) {
        vector<string> words;
        stringstream ss(line);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        cout << learner.Learn(words) << "\n";
    }
    cout << "=== known words ===\n";
    for (auto word : learner.KnownWords()) {
        cout << word << "\n";
    }
}
