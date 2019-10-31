#include <iostream>
#include "reverse.h"
int main ( int argc, char **argv )
{
    std::vector<int> v1 = {4, 3, 2, 1};
    v1 = Reversed ( v1 );
    for ( const auto& e : v1 ) {
        std::cout << e << ' ' ;
    }
    
    std::cout << "====\n";
    std::vector<int> v2 = {5, 4, 3, 2, 1};
    v2 = Reversed ( v2 );
    for ( const auto& e : v2 ) {
        std::cout << e << ' ' ;
    }
    return 0;
}
