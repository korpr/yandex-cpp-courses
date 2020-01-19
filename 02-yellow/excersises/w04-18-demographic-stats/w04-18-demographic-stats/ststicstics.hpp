//
//  ststicstics.hpp
//  w04-18-demographic-stats
//
//  Created by Sergey Gordeev on 19/01/2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#ifndef ststicstics_hpp
#define ststicstics_hpp
#include <vector>
#include "person.hpp"

#include <stdio.h>

template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
  if (range_begin == range_end) {
    return 0;
  }
  std::vector<typename InputIt::value_type> range_copy(range_begin, range_end);
  auto middle = begin(range_copy) + range_copy.size() / 2;
  nth_element(
      begin(range_copy), middle, end(range_copy),
      [](const Person& lhs, const Person& rhs) {
        return lhs.age < rhs.age;
      }
  );
  return middle->age;
}

void PrintStats(std::vector<Person> persons);
#endif /* ststicstics_hpp */
