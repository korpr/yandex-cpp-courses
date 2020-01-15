
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include "ostream_overloads.h"
using namespace std;
int main ( int argc, char **argv )
{
    map<int, int> m {{1, 2}, {2, 3}};
    std::cout << m << endl;
    pair<std::string, int> p = make_pair ( "one", 1 );
    std::cout << p << endl;
    set<int> s = {1, 2, 3};
    std::cout << s << endl;
    vector<int> v = {1, 2, 3};
    std::cout << v << endl;
    return 0;
}
