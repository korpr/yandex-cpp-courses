#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main ( int argc, char **argv )
{
    ifstream is ( "input.txt" );
    ofstream os ( "output.txt" );
    if ( is.is_open() ) {
        string line;
        while ( getline ( is, line ) ) {
            os << line << endl;
        }
    }
    
    return 0;
}
