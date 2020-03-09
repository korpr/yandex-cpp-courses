//
//  date.cpp
//  w06-28-capstone
//
//  Created by Sergey Gordeev on 11.02.2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#include "date.h"
#include <iomanip>


Date::Date(const Year anYear,const  Month aMonth,const Day aDay):year(anYear),month(aMonth),day(aDay){};
Date ParseDate(std::istringstream& is){
    int y,m,d;
    is >> y;
    is.ignore();
    is >> m;
    is.ignore();
    is >> d;
    return Date(y,m,d);
};
std::ostream& operator<<(std::ostream& os, const DateUnit& unit){
    os << unit.value;
    return os;
};

std::ostream& operator<<(std::ostream& os, const Date& date){
    os << std::setw(4) << std::setfill('0') << date.year
    << "-" << std::setw(2) << std::setfill('0') << date.month
    << "-" << std::setw(2) << std::setfill('0') <<  date.day;
    return os;
};
