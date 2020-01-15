#ifndef TESTRUNNER_H
#define TESTRUNNER_H
#include <string>
#include <iostream>
#include <sstream>
#include <exception>

class TestRunner
{
private:
    unsigned int failedCount;
public:
    TestRunner() : failedCount ( 0 ) {} ;
    ~TestRunner()
    {
        if ( failedCount ) {
            std::cerr << failedCount << " unit tests failed. Terminate" << std::endl;
            exit ( 1 );
        }
    }
    
    template <class TestFunc>
    void runTest ( TestFunc func, const std::string& name )
    {
        {
            try {
                func();
                std::cerr << "[  OK  ] " ;
            } catch ( const std::exception& e ) {
                ++failedCount;
                std::cerr << "[ FAIL ] " << " reason: " << e.what();
            }
            std::cerr << name << std::endl;
        }
    }
    
};

#endif // TESTRUNNER_H

template<typename EXPECTED, typename ACTUAL>
void AssertEq ( const EXPECTED& ex, const ACTUAL& act, const std::string& msg )
{
    if ( ex != act ) {
        std::ostringstream os;
        os << ex << " != " << act << " msg: " << msg;
        throw std::runtime_error ( os.str() );
    }
}

void AssertTrue ( const bool actual, const std::string& msg )
{
    AssertEq ( true, actual, msg );
}
