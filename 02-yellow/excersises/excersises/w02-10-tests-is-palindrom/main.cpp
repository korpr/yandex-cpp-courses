#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

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

bool IsPalindrom ( const string& str )
{
    size_t lastElem = str.size() - 1;
    size_t center = str.size() / 2 ;
    for ( size_t idx = 0; idx <  center ; ++idx ) {
        if ( str[idx] != str[lastElem - idx] ) {
            return false;
        }
    }
    return true;
};
void Test()
{
    AssertEqual ( true, IsPalindrom ( "" ), "Empty" );
    AssertEqual ( true, IsPalindrom ( "a" ), "a" );
    AssertEqual ( true, IsPalindrom ( "aa" ), "aa" );
    AssertEqual ( true, IsPalindrom ( "aaa" ), "aaa" );
    AssertEqual ( true, IsPalindrom ( "aba" ), "aba"  );
    AssertEqual ( true, IsPalindrom ( "abba" ), "abba"  );
    AssertEqual ( true, IsPalindrom ( "ababa" ), "ababa" );
    AssertEqual ( true, IsPalindrom ( "ab ba" ), "ab ba" );
    
    AssertEqual ( false, IsPalindrom ( "ab" ), "ab" );
    AssertEqual ( false, IsPalindrom ( "abca" ), "ab" );
    AssertEqual ( false, IsPalindrom ( "abab" ), "abab" );
    AssertEqual ( false, IsPalindrom ( "ababc" ), "ababc" );
    AssertEqual ( false, IsPalindrom ( "ab bc" ), "ab bc" );
}
int main()
{
    TestRunner runner;
    runner.RunTest ( Test, "Test" );
    // Ð´Ð¾Ð±Ð°Ð²ÑŒÑ‚Ðµ ÑÑŽÐ´Ð° ÑÐ²Ð¾Ð¸ Ñ‚ÐµÑÑ‚Ñ‹
    return 0;
}
