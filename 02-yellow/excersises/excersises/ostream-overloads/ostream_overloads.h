#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>

template < class K, class V >
std::ostream& operator<< ( std::ostream& os, const std::pair<K, V>& p )
{
    os << "{" << p.first << ", " << p.second << "}";
    
    return os;
}


template < class K, class V >
std::ostream& operator<< ( std::ostream& os, const  std::map<K, V>& m )
{
    os << "{";
    bool first {true};
    for ( const auto& p : m ) {
        if ( !first ) {
            os << ", ";
        }
        first = false;
        os << p;
        
    }
    os << "}";
    return os;
}

template <class V>
std::ostream& operator << ( std::ostream& os, const std::set<V>& s )
{
    os << "{";
    bool first {true};
    for ( const auto& x : s ) {
        if ( !first ) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class V>
std::ostream& operator << ( std::ostream& os, const std::vector<V>& s )
{
    os << "[";
    bool first {true};
    for ( const auto& x : s ) {
        if ( !first ) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "]";
}
