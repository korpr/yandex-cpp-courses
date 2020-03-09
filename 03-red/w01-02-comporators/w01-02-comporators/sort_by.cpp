#include <ostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include "airline_ticket.h"
using namespace std;

#define SORT_BY(field)  [](const AirlineTicket& lhs, const AirlineTicket& rhs){return lhs.field < rhs.field;}
std::tuple<int,int,int> wrap_date(const Date& date);
bool sortBy(const AirlineTicket& lhs, const AirlineTicket& rhs);

std::ostream& operator<<(std::ostream& os, const Date& date){
    os
    << std::setw(4) << std::setfill('0') << date.year  << "."
    << std::setw(2) << std::setfill('0') << date.month << "."
    << std::setw(2) << std::setfill('0') << date.day;
    return os;
}

bool sortBy(const AirlineTicket& lhs, const AirlineTicket& rhs){
    return true;
} 
std::tuple<int,int,int> wrap_date(const Date& date){
    return std::make_tuple(date.year,date.month,date.day);
}
bool operator==(const Date& d1, const Date d2){
    return wrap_date(d1) == wrap_date(d2);
}

bool operator<(const Date& d1, const Date d2){
    return wrap_date(d1) < wrap_date(d2);
}




