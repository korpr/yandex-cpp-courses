//
//  persona.cpp
//  w04-21-names-and-surnames-v4
//
//  Created by Sergey Gordeev on 22/01/2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#include "person.hpp"

std::string Person::ValueForYear(const std::map<int, std::string> &values, const int &year) const{
    auto upper = values.upper_bound(year);
    if (upper == values.begin() ){
        return "";
    }
    
    return (--upper)->second;
    
}
void Person::ChangeFirstName(int year, const std::string& first_name) {
    names[year] = first_name;
}
void Person::ChangeLastName(int year, const std::string& last_name) {
    surnames[year] = last_name;
    
}
std::string Person::GetFullName(int year) {
    const std::string first_name = ValueForYear(names, year);
    const std::string last_name = ValueForYear(surnames, year);
    if (first_name.empty() && last_name.empty()) {
        return "Incognito";
    } else if (first_name.empty()) {
        return last_name + " with unknown first name";
    } else if (last_name.empty()) {
        return first_name + " with unknown last name";
    } else {
        return first_name + " " + last_name;
    }
    return "";
}
