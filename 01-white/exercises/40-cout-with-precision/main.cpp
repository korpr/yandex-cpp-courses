#include <iostream>
#include <fstream>

using namespace std;

int main ( int argc, char **argv )
{
    ifstream is ( "input.txt" );
    if ( is.is_open() ) {
        double val;
        while ( is >> val ) {
            cout << fixed << setprecision ( 3 ) << val << endl;
        }
    }
    return 0;
}
