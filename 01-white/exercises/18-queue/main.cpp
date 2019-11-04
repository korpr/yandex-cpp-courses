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
            cout << count ( people.begin(), people.end(), true );
            continue;
        }
        if ( command == "COME" ) {
            int delta = 0;
            cin >> delta;
            //todo:check if new  sizev less then zero
            people.resize ( people.size() + delta );
            continue;
        }
        if ( command == "QUIET" ) {
            int idx = 0;
            cin >> idx;
            people[idx] = false;
            continue;
        }
        
        if ( command == "WORRY" ) {
            int idx = 0;
            cin >> idx;
            people[idx] = true;
            continue;
        }
    }
    
    return 0;
}
