//
//  person.hpp
//  w04-18-demographic-stats
//
//  Created by Sergey Gordeev on 19/01/2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#ifndef person_hpp
#define person_hpp

#include <stdio.h>

enum class Gender {
  FEMALE,
  MALE
};


struct Person {
  int age;  // возраст
  Gender gender;  // пол
  bool is_employed;  // имеет ли работу
};
#endif /* person_hpp */
