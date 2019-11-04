#include <iostream>
#include <map>
#include <string>

using namespace std;
map<char, size_t> separated ( const string& world )
{
    map<char, size_t> result;
    for ( auto c : world ) {
        ++result[c];
    }
    return result;
}
bool IsAnagram ( const string& first, const string& second )
{
    return separated ( first ) == separated ( second );
}
int main ( int argc, char **argv )
{
    int n = 0;
    std::cin >> n ;
    for ( size_t i = 0; i < n; ++i ) {
        string first;
        string second;
        cin >> first >> second;
        cout << ( IsAnagram ( first, second ) ? "YES" : "NO" ) << endl;
    }
    return 0;
}
