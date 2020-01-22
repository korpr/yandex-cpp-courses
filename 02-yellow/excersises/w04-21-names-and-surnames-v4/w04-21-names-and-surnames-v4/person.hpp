//
//  persona.hpp
//  w04-21-names-and-surnames-v4
//
//  Created by Sergey Gordeev on 22/01/2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#ifndef person_hpp
#define person_hpp
#include <map>
#include <string>

class Person {
public:
    void ChangeFirstName(int year, const std::string& first_name);
    void ChangeLastName(int year, const std::string& last_name);
    std::string GetFullName(int year);
private:
    std::string ValueForYear(const std::map<int,std::string>& map,const int& year) const;
    std::map<int,std::string> names;
    std::map<int,std::string> surnames;
};

#endif /* persona_hpp */
