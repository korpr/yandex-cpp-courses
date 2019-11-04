#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main ( int argc, char **argv )
{
    string command;
    int n;
    vector<bool> people;
    cin >> n;
    
    for ( int i = 0; i < n; i++ ) {
        cin >> command;
        if ( command == "WORRY_COUNT" ) {
            cout << count ( people.begin(), people.end(), true ) << endl;
        }else
        if ( command == "COME" ) {
            int delta = 0;
            cin >> delta;
            //todo:check if new  sizev less then zero
            people.resize ( people.size() + delta, false );
            continue;
        }else
        if ( command == "QUIET" || command == "WORRY" ) {
            int idx = 0;
            cin >> idx;
            people[idx] = command == "WORRY";
            continue;
        }
    }
    
    return 0;
}
