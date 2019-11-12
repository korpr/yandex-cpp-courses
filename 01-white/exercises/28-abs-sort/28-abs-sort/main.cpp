#include <iostream>
#include <vector>
#include <algorithm>

int main ( int argc, char **argv )
{
    int n = 0;
    std::cin >> n;
    std::vector<int> ints ( n );
    for ( auto& element : ints ) {
        std::cin >> element;
    }
    std::sort (
        ints.begin(),
        ints.end(),
    [] ( int f, int s ) {
        return std::abs ( f ) < std::abs ( s );
    }
    );
    for ( const auto& element : ints ) {
        std::cout << element << " ";
    }
    return 0;
}
