//
//  database.hpp
//  w06-28-capstone
//
//  Created by Sergey Gordeev on 11.02.2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#ifndef database_hpp
#define database_hpp

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <map>
#include <algorithm>
#include "date.h"
#include "node.h"

typedef std::pair<Date,std::string> row_t;
bool operator<(const row_t& r1, const row_t& r2);
class Database{
public:
    void Add(const Date& date, const std::string& event);
    
    void Print(std::ostream& os);
    
    row_t Last(const Date& date) const;
    
    std::vector<pair<Date, std::string>> All();
    
    template <class Predicate>
    int RemoveIf(Predicate predicate){
        auto newEnd = remove_if(begin(rows), end(rows),
            [predicate](row_t r){
                return predicate(r.first, r.second);
        });
        auto removedCounter =  end(rows) - newEnd;
        rows.erase(newEnd, end(rows));
        return static_cast<int>(removedCounter);
    };
    template <class Predicate>
    std::vector<pair<Date, std::string>> FindIf(Predicate predicate) const{
        std::vector<row_t> result;
        std::copy_if(begin(rows), end(rows), back_inserter(result), [predicate](row_t r){
            return predicate(r.first, r.second);});
        std::stable_sort(begin(result),end(result));
        return result;
    };
private:
    std::vector<row_t> rows;
};
#endif /* database_hpp */
