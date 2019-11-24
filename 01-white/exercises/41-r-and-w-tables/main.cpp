#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;
const size_t CELL_WIDTH {10};
int main ( int argc, char **argv )
{

    ifstream is ( "input.txt" );
    
    if ( is.is_open() ) {
        size_t row{0};
        size_t column {0};
        is >> row >> column;
        is.ignore ( 1 );
        for ( size_t r {0}; r < row; ++r ) {
            if ( r > 0 ) {
                cout << endl;
            }
            string line;
            getline ( is, line );
            stringstream ss ( line );
            for ( size_t c{0}; c < column; ++c ) {
                string cell;
                getline ( ss, cell, ',' );
                
                cout << right << setw ( CELL_WIDTH ) << cell;
            }
        }
        
    } else {
        cout << "file not found\n";
    }
    
    return 0;
}
