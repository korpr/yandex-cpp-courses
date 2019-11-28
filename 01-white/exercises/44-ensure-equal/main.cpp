#include <iostream>
#include "ensure-equal.h"

int main ( int argc, char **argv )
{
    try {
        EnsureEqual ( "C++ White", "C++ White" );
        EnsureEqual ( "C++ White", "C++ Yellow" );
    } catch ( runtime_error& e ) {
        cout << e.what() << endl;
    }
    return 0;
}
