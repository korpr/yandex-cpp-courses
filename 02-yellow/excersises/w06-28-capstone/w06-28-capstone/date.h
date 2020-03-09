//
//  date.hpp
//  w06-28-capstone
//
//  Created by Sergey Gordeev on 11.02.2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#ifndef date_hpp
#define date_hpp

#include <iostream>
#include <sstream>

struct DateUnit{
    explicit DateUnit(int aValue):value(aValue){}
    int value;
    bool operator <(const DateUnit& du) const{
        return value < du.value;
    }
    bool operator <=(const DateUnit& du) const{
        return value <= du.value;
    }
    bool operator ==(const DateUnit& du) const{
        return value == du.value;
    }
    
    bool operator !=(const DateUnit& du) const{
        return value != du.value;
    }
    
    bool operator >(const DateUnit& du) const{
        return value > du.value;
    }
    
    bool operator >=(const DateUnit& du) const{
        return value >= du.value;
    }
};

struct Year: public DateUnit{
    Year(int value): DateUnit(value){};
};

struct Month: public DateUnit{
    Month(int value): DateUnit(value){};
};

struct Day: public DateUnit{
    Day(int value): DateUnit(value){};
};
struct Date{
    Date(const Year anYear,const Month aMonth,const Day aDay);
    Year year;
    Month month;
    Day day;
    
    std::tuple<Year,Month,Day> asTuple() const{
        //TODO:: cache  tuple
        return std::make_tuple(year, month, day);
    }
    bool operator==(const Date& other) const{
        return asTuple() == other.asTuple();
    }
    bool operator!=(const Date& other) const{
        return asTuple() != other.asTuple();
    }
    bool operator<(const Date& other) const{
        return asTuple() < other.asTuple();
    }
};

Date ParseDate(std::istringstream& is);

std::ostream& operator<<(std::ostream& os, const Date& date);
#endif /* date_hpp */
