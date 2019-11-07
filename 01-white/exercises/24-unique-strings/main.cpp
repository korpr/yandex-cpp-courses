#include <iostream>
#include <set>
#include <string>

int main ( int argc, char **argv )
{
    size_t n = 0;
    std::cin >> n;
    std::set<std::string> unique_strings;
    std::string str = "";
    for ( size_t i; i < n; ++i ) {
        std::cin >> str;
        unique_strings.insert ( str );
    }
    std::cout << unique_strings.size();
    return 0;
}
