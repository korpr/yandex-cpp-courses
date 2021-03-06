#include <iostream>
#include "sorted.h"


void PrintSortedStrings ( SortedStrings& strings )
{
    for ( const string& s : strings.GetSortedStrings() ) {
        cout << s << " ";
    }
    cout << endl;
}
int main ( int argc, char **argv )
{
    SortedStrings strings;
    
    strings.AddString ( "first" );
    strings.AddString ( "third" );
    strings.AddString ( "second" );
    PrintSortedStrings ( strings );
    
    strings.AddString ( "second" );
    PrintSortedStrings ( strings );
    return 0;
}
