#include "airline_ticket.h"
#include <iomanip>


using namespace std;

#define UPDATE_FIELD(ticket, field, values)  \
{auto res = values.find(#field);\
if (res != values.end()) {\
istringstream is(res->second);\
is >> ticket.field;}\
}\


std::tuple<int,int,int> wrap_date(const Date& date){
    return std::make_tuple(date.year,date.month,date.day);
}
bool operator==(const Date& d1, const Date d2){
    return wrap_date(d1) == wrap_date(d2);
}

std::tuple<int,int> wrap_time(const Time& time){
    return std::make_tuple(time.hours,time.minutes);
}
bool operator==(const Time& t1, const Time& t2){
    return wrap_time(t1) == wrap_time(t2);
}
std::ostream& operator<<(std::ostream& os, const Date& date){
    os
    << std::setw(4) << std::setfill('0') << date.year  << "."
    << std::setw(2) << std::setfill('0') << date.month << "."
    << std::setw(2) << std::setfill('0') << date.day;
    return os;
    };
    
    std::ostream& operator<<(std::ostream& os, const Time& time){
    os
    << std::setw(2) << std::setfill('0') << time.hours << ":"
    << std::setw(2) << std::setfill('0') << time.minutes;
    return os;
    };
    std::istream& operator>>(std::istream& is, Date& date){
    is>> date.year;
    is.ignore(1);
    is>>date.month;
    is.ignore(1);
    is>>date.day;
    return is;
    };
    
    std::istream& operator>>(std::istream& is, Time& time){
    is>> time.hours;
    is.ignore(1);
    is>>time.minutes;
    return is;
    }
