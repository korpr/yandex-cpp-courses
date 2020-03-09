//
//  collection_helper.hpp
//  u-tests
//
//  Created by Sergey Gordeev on 16/01/2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//
#pragma once
#include <string>
#include <map>
#include <set>
#include <vector>
#include <ostream>



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
    os << "}";
    return os;
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
