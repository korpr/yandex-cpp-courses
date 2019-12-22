#include <iostream>
#include <exception>
#include <map>

using namespace std;

template <typename K, typename V>
V& GetRefStrict ( map<K, V>& m, K key )
{
    if ( m.count ( key ) == 0 ) {
        throw runtime_error ( "no such key" );
    }
    return m.at ( key );
};

int main ( int argc, char **argv )
{
    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict ( m, 0 );
    item = "newvalue";
    cout << m[0] << endl;
    return 0;
}
