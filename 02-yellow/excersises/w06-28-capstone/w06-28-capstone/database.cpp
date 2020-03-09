//
//  database.cpp
//  w06-28-capstone
//
//  Created by Sergey Gordeev on 11.02.2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#include "database.h"
bool operator<(const row_t& r1, const row_t& r2){
   return r1.first < r2.first;
};
void Database::Add(const Date& date, const std::string& event){
    if (!count_if(begin(rows),end(rows),[date, event](row_t r) {
        return r.first == date && r.second == event;
    })){
      rows.push_back(make_pair(date, event));
    }
    
};


void Database::Print(std::ostream& os){
   
    static auto predicate = [](const Date& d,const string& s){
        return true;
    };
    auto rows = FindIf(predicate);
    for (const auto& row : rows){
        os << row.first << " " << row.second << endl;
    }
};

row_t Database::Last(const Date& date) const{
    DateComparisonNode dcn(Comparison::LessOrEqual, date);
    auto results = FindIf([dcn](const Date& date, const std::string& str){
        return dcn.Evaluate(date, str);
    });
    
    if (results.size() == 0){
        throw invalid_argument("found nothing");
    }
    return results.back();
};




std::vector<pair<Date, std::string>> Database::All(){
    return rows;
};
