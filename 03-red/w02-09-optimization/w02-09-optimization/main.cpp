#include "student.h"
#include "test_runner.h"
#include "profiler.h"

#include <algorithm>

using namespace std;

//ÐžÐ¿Ñ‚Ð¸Ð¼Ð¸Ð·Ð¸Ñ€ÑƒÐ¹Ñ‚Ðµ ÑÑ‚Ñƒ Ñ„ÑƒÐ½ÐºÑ†Ð¸ÑŽ
bool Compare(const Student& first,const Student& second) {
  return first.Less(second);
}

void TestComparison() {
  Student newbie {
    "Ivan", "Ivanov", {
      {"c++", 1.0},
      {"algorithms", 3.0}
    },
    2.0
  };

  Student cpp_expert {
    "Petr", "Petrov", {
      {"c++", 9.5},
      {"algorithms", 6.0}
    },
    7.75
  };

  Student guru {
    "Sidor", "Sidorov", {
      {"c++", 10.0},
      {"algorithms", 10.0}
    },
    10.0
  };
  ASSERT(Compare(guru, newbie));
  ASSERT(Compare(guru, cpp_expert));
  ASSERT(!Compare(newbie, cpp_expert));
}

void TestSorting() {
  vector<Student> students {
    {"Sidor", "Sidorov", {{"maths", 2.}}, 2.},
    {"Semen", "Semenov", {{"maths", 4.}}, 4.},
    {"Ivan", "Ivanov", {{"maths", 5.}}, 5.},
    {"Petr", "Petrov", {{"maths", 3.}}, 3.},
    {"Alexander", "Alexandrov", {{"maths", 1.}}, 1.}
  };

  sort(students.begin(), students.end(), Compare);

  ASSERT(is_sorted(students.begin(), students.end(),
    [](Student first, Student second) {
      return first.Less(second);
    })
  );
}

void TestPerf(){
    vector<Student> students;
    for (size_t  i = 0 ; i  < 200000; ++i){
        double r = rand();
        students.push_back({to_string(i), to_string(i), {{"maths", 2.}}, r });
    }
    {
        LOG_DURATION("SORT")
        sort(students.begin(), students.end(), Compare);
    }
}
int main() {
  TestRunner tr;
  RUN_TEST(tr, TestComparison);
  RUN_TEST(tr, TestSorting);
  RUN_TEST(tr, TestPerf);
  return 0;
}
