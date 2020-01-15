#include <iostream>
#include <vector>
#include <map>
using namespace std;

template <typename V>
V Sqr ( const V& v );

template < typename K, typename V >
pair<K, V> operator* ( const pair<K, V>& lhs, const pair<K, V>& rhs );

template < typename K, typename V >
pair<K, V> operator* ( const  pair<K, V>& lhs, const pair<K, V>& rhs );

template <typename V>
vector<V> Sqr ( const vector<V>& v );

template <typename K, typename V>
map<K, V> Sqr ( const map<K, V>& m );
/////////////////////////////////////////////////////////
template <typename V>
V Sqr ( const V& v )
{
    return v * v;
}
template < typename K, typename V >
pair<K, V> operator* ( const  pair<K, V>& lhs, const pair<K, V>& rhs )
{
    return make_pair ( lhs.first * rhs.first, lhs.second * rhs.second );
}

template <typename V>
vector<V> Sqr ( const vector<V>& v )
{
    vector<V> n ;
    for ( const auto& e : v ) {
        n.push_back ( Sqr ( e ) );
    }
    return n;
}

template <typename K, typename V>
map<K, V> Sqr ( const map<K, V>& m )
{
    map<K, V> n;
    for ( const auto & e : m ) {
        n[e.first] = ( Sqr ( e.second ) );
    }
    return n;
}

int main ( int argc, char **argv )
{
// Пример вызова функции
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for ( int x : Sqr ( v ) ) {
        cout << ' ' << x;
    }
    cout << endl;
    
    map<int, pair<int, int>> map_of_pairs = {
        {4, {5, 2}},
        {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for ( const auto& x : Sqr ( map_of_pairs ) ) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
    return 0;
}
