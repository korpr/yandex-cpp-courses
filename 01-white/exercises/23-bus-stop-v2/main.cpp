#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main ( int argc, char **argv )
{
    int q = 0;
    std::cin >> q;
    map<vector<string>, size_t> stops_name;
    for ( size_t i = 0; i < q; ++i ) {
        int n = 0;
        cin >> n;
        vector<string> stops ( n );
        for ( auto& stop : stops ) {
            cin >> stop;
        }
        
        
        if ( stops_name.count ( stops ) ) {
            cout << "Already exists for " << stops_name[stops];
        } else {
            size_t next_number = stops_name.size() + 1;
            stops_name[stops] = next_number;
            cout << "New bus " << stops_name[stops];
        }
        cout << endl;
    }
    
    return 0;
}
