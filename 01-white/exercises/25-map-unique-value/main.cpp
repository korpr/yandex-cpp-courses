#include <iostream>
#include "func.h"

int main ( int argc, char **argv )
{
    std::set<std::string> values = BuildMapValuesSet ( {
        {1, ""},
        {2, ""},
        {3, ""},
        {4, "even"},
        {5, "odd"},
        {6, "odd"},
        {7, "odd1"}
    } );
    
    for ( const auto& value : values ) {
        std::cout << value << std::endl;
    }
}
