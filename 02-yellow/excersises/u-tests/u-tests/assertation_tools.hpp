//
//  assertation_tools.hpp
//  u-tests
//
//  Created by Sergey Gordeev on 16/01/2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//
#pragma once

#include <sstream>
#include <exception>
#include "collection_helper.hpp"


template<typename EXPECTED, typename ACTUAL>
void AssertEqual ( const EXPECTED& ex, const ACTUAL& act, const std::string& msg )
{
    if ( ex != act ) {
        std::ostringstream os;
        os << ex << " != " << act << " msg: " << msg;
        throw std::runtime_error ( os.str() );
    }
}
template<typename EXPECTED, typename ACTUAL>
void AssertEq ( const EXPECTED& ex, const ACTUAL& act, const std::string& msg )
{
    if ( ex != act ) {
        std::ostringstream os;
        os << ex << " != " << act << " msg: " << msg;
        throw std::runtime_error ( os.str() );
    }
}

void AssertTrue ( const bool actual, const std::string& msg );
void Assert ( const bool actual, const std::string& msg );
