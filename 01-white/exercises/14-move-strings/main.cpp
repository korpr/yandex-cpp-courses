#include <iostream>
#include <vector>
#include <string>
#include "move.h"

int main ( int argc, char **argv )
{
    std::vector<std::string> v1 = {"v11", "v12"};
    std::vector<std::string> v2 = {"v21", "v22"};
    MoveStrings ( v1, v2 );
    
    std::cout << v1.size() << "\n";
    for ( const auto& e : v2 ) {
        std::cout << e << " ";
    }
    return 0;
}
