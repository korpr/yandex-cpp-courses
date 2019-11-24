#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main ( int argc, char **argv )
{
    ifstream is ( "input.txt" );
    if ( is.is_open() ) {
        string line;
        while ( getline ( is, line ) ) {
            cout << line << endl;
        }
    }
    
    return 0;
}
