#include <iostream>
#include <vector>

int main ( int argc, char **argv )
{
    int a = 0;
    std::cin >> a;
    std::vector<int> result;
    while ( a > 0 ) {
        result.push_back ( a % 2 );
        a /= 2;
    }
    
    for ( auto it =  result.rbegin(); it !=  result.rend(); ++it ) {
        std::cout << *it;
    }
    
    return 0;
}
