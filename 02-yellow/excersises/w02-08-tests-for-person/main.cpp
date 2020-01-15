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

class Person
{
public:


    void ChangeFirstName ( int year, const string& first_name )
    {
        first_names[year] = first_name;
    }
    void ChangeLastName ( int year, const string& last_name )
    {
        last_names[year] = last_name;
    }
    string GetFullName ( int year )
    {
        const string first_name = GetRecordForYear ( first_names, year );
        const string last_name = GetRecordForYear ( last_names, year ) ;
        
        if ( first_name.empty() && last_name.empty() ) {
            return "Incognito";
        } else if ( last_name.empty() ) {
            return  first_name + " with unknown last name";
        } else if ( first_name.empty() ) {
            return  last_name + " with unknown first name";
        } else {
            return first_name + " " + last_name;
        }
    }
private:
    map<int, string> first_names;
    map<int, string> last_names;
    string GetRecordForYear (  map<int, string> names, int year )
    {
        string result;
        for ( const auto& element : names ) {
            if ( element.first <= year ) {
                result = element.second;
            } else {
                break;
            }
        }
        return result;
    }
};
void GetFullNameTest()
{
    {
        Person p;
        AssertEqual ( "Incognito", p.GetFullName ( 1990 ), "Incognito 1990" );
        AssertEqual ( "Incognito", p.GetFullName ( 1991 ), "Incognito 1991" );
        AssertEqual ( "Incognito", p.GetFullName ( 1992 ), "Incognito 1992" );
    }
    {
        Person p;
        p.ChangeFirstName ( 1991, "FN" );
        p.ChangeLastName ( 1991, "LN" );
        AssertEqual ( "Incognito", p.GetFullName ( 1990 ), "Incognito 1990, But known in 1991" );
        AssertEqual ( "FN LN", p.GetFullName ( 1991 ), "FN LN in 1991" );
        AssertEqual ( "FN LN", p.GetFullName ( 1992 ), "FN LN in 1992" );
        
        p.ChangeFirstName ( 1990, "FN-1990" );
        AssertEqual ( "FN-1990 with unknown last name", p.GetFullName ( 1990 ), "FN-1990 in 1990" );
        AssertEqual ( "FN LN", p.GetFullName ( 1991 ), "FN LN in 1991" );
        AssertEqual ( "FN LN", p.GetFullName ( 1992 ), "FN LN in 1992" );
        
        p.ChangeLastName ( 1989, "LN-1989" );
        AssertEqual ( "LN-1989 with unknown first name", p.GetFullName ( 1989 ), "LN-1989 in 1989" );
        AssertEqual ( "FN-1990 LN-1989", p.GetFullName ( 1990 ), "FN-1990 LN-1989 in 1990" );
        AssertEqual ( "FN LN", p.GetFullName ( 1991 ), "FN LN in 1991" );
        AssertEqual ( "FN LN", p.GetFullName ( 1992 ), "FN LN in 1992" );
    }
}
void OnlyLastnameTest()
{
    Person p;
    p.ChangeLastName ( 1991, "LN" );
    
    AssertEqual ( "Incognito", p.GetFullName ( 1990 ), "Incognito 1990, But known in 1991" );
    AssertEqual ( "LN with unknown first name", p.GetFullName ( 1991 ), "LN only 1991" );
    AssertEqual ( "LN with unknown first name", p.GetFullName ( 1992 ), "Incognito 1992, But known in 1991" );
}
void OnlyFirstnameTest()
{
    Person p;
    p.ChangeFirstName ( 1991, "FN" );
    
    AssertEqual ( "Incognito", p.GetFullName ( 1990 ), "Incognito 1990, But known in 1991" );
    AssertEqual ( "FN with unknown last name", p.GetFullName ( 1991 ), "FN only 1991" );
    AssertEqual ( "FN with unknown last name", p.GetFullName ( 1992 ), "Incognito 1992, But known in 1991" );
}

int main()
{
    TestRunner runner;
    runner.RunTest ( GetFullNameTest, "GetFullNameTest" );
    runner.RunTest ( OnlyLastnameTest, "OnlyLastnameTest" );
    runner.RunTest ( OnlyFirstnameTest, "OnlyFirstnameTest" );
    return 0;
}
