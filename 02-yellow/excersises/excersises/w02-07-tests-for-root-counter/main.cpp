#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <math.h>
#include <random>
using namespace std;

template <class T>
ostream& operator << ( ostream& os, const vector<T>& s )
{
    os << "{";
    bool first = true;
    for ( const auto& x : s ) {
        if ( !first ) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class T>
ostream& operator << ( ostream& os, const set<T>& s )
{
    os << "{";
    bool first = true;
    for ( const auto& x : s ) {
        if ( !first ) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class K, class V>
ostream& operator << ( ostream& os, const map<K, V>& m )
{
    os << "{";
    bool first = true;
    for ( const auto& kv : m ) {
        if ( !first ) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual ( const T& t, const U& u, const string& hint = {} )
{
    if ( t != u ) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if ( !hint.empty() ) {
            os << " hint: " << hint;
        }
        throw runtime_error ( os.str() );
    }
}

void Assert ( bool b, const string& hint )
{
    AssertEqual ( b, true, hint );
}

class TestRunner
{
public:
    template <class TestFunc>
    void RunTest ( TestFunc func, const string& test_name )
    {
        try {
            func();
            cerr << test_name << " OK" << endl;
        } catch ( exception& e ) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        } catch ( ... ) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }
    
    ~TestRunner()
    {
        if ( fail_count > 0 ) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit ( 1 );
        }
    }
    
private:
    int fail_count = 0;
};

int GetDistinctRealRootCount ( double a, double b, double c )
{
    set<double> roots;
    if ( a == 0 ) {
        if ( b != 0 ) {
            roots.insert ( -c / b );
            
        }
        
    } else {
        double d = std::pow ( b, 2 ) - 4 * a * c;
        if ( d >= 0 ) {
            double sqrtD {std::sqrt ( d ) };
            double v1 = - ( b + sqrtD ) / ( 2 * a );
            double v2 = - ( b - sqrtD ) / ( 2 * a );
            roots.insert ( v1 );
            roots.insert ( v2 );
        }
    }
    return roots.size();
    
};
void RootsBetweenZeroAndTwo()
{
    random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen ( rd() );
    uniform_real_distribution<> unif ( -15, 15 );
    
    for ( auto i = 0; i < 225; ++i ) {
        const auto a = unif ( gen );
        const auto b = unif ( gen );
        const auto c = unif ( gen );
        
        const auto count = GetDistinctRealRootCount ( a, b, c );
        
        Assert ( count >= 0 && count <= 2, "only 0, 1, 2 roots acceptable" );
    }
}
void TwoRoots()
{
    AssertEqual ( 2, GetDistinctRealRootCount ( 3, -4, 1 ), "( 3, -4, 1 )" );
    AssertEqual ( 2, GetDistinctRealRootCount ( 1, 0, -1 ), "( 1, 0, -1 )" );
    AssertEqual ( 2, GetDistinctRealRootCount ( 1, 1, 0 ), "( 1, 1, 0 )" );
}
void OneRoot ()
{
    AssertEqual ( 1, GetDistinctRealRootCount ( 1, 0, 0 ), "( 1, 0, 0 )" );
    AssertEqual ( 1, GetDistinctRealRootCount ( 0, 1, 0 ), "( 0, 1, 0 )" );
    AssertEqual ( 1, GetDistinctRealRootCount ( 0, 1, 1 ), "( 0, 1, 1 )" );
}

void ZeroRoots()
{
    AssertEqual ( 0, GetDistinctRealRootCount ( 1, 1, 1 ), "( 1, 1, 1 )" );
    AssertEqual ( 0, GetDistinctRealRootCount ( 0, 0, 1 ), "( 0, 0, 1 )" );
    AssertEqual ( 0, GetDistinctRealRootCount ( 1, 0, 1 ), "( 0, 1, 1 )" );
}
int main()
{
    TestRunner runner;
    runner.RunTest ( RootsBetweenZeroAndTwo, "RootsBetweenZeroAndTwo" );
    runner.RunTest ( TwoRoots, "TwoRoots" );
    runner.RunTest ( OneRoot, "OneRoot" );
    runner.RunTest ( ZeroRoots, "ZeroRoots" );
    return 0;
}
