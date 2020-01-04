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

class Rational
{
public:

    Rational ( int aNumerator = 0, int aDenominator = 1 )
    {
        if ( !aNumerator ) {
            numerator = 0;
            denominator = 1;
        } else {
            int common  = gcd ( aNumerator, aDenominator );
            numerator = aNumerator / common ;
            denominator = aDenominator / common ;
            if ( denominator < 0 ) {
                denominator = -denominator;
                numerator = -numerator;
            }
        }
    }
    
    int Numerator() const
    {
        return numerator;
    }
    
    int Denominator() const
    {
        return denominator;
    }
    
    
    
private:
    int numerator;
    int denominator;
    int gcd ( int a, int b )
    {
        if ( !b ) {
            return a;
        }
        return gcd ( b, a % b );
    }
    
};
Rational operator+ (  const Rational& lhs, const Rational& rhs )
{
    return {lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator() };
}
Rational operator- (  const Rational& lhs, const Rational& rhs )
{
    return {lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator() };
}
Rational operator* (  const Rational& lhs, const Rational& rhs  )
{
    return  {lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator() };
}
Rational operator/ (  const Rational& lhs, const Rational& rhs  )
{
    return  {lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator() };
}
bool operator== (  const Rational& lhr, const Rational& rhr )
{
    return lhr.Numerator() == rhr.Numerator() && lhr.Denominator() == rhr.Denominator();
}

bool operator< ( const Rational& lhr, const Rational& rhr )
{
    return ( lhr.Numerator() * rhr.Denominator() ) < ( rhr.Numerator() * lhr.Denominator() );
}

ostream& operator<< ( ostream& os, const Rational& r )
{
    os << r.Numerator() << '/' << r.Denominator();
    return os;
}
istream& operator>> ( istream& is, Rational& r )
{

    if ( !is ) {
        return is;
    }
    int numerator{r.Numerator() }, denominator{r.Denominator() };
    is >> numerator;
    is.ignore ( 1 );
    is >> denominator;
    r = Rational ( numerator, denominator );
    return is;
}
void Default()
{
    {
        Rational r;
        AssertEqual ( 0, r.Numerator(), "Def const numerator" );
        AssertEqual ( 1, r.Denominator(), "Def const denominator" );
    }
    {
        Rational r ( 0, 3 );
        AssertEqual ( 0, r.Numerator(), "0/3 numerator" );
        AssertEqual ( 1, r.Denominator(), "0/3 denominator" );
    }
    {
        Rational r ( 0, -3 );
        AssertEqual ( 0, r.Numerator(), "0/-3 numerator" );
        AssertEqual ( 1, r.Denominator(), "0/-3 denominator" );
    }
}

void Positive()
{
    {
        Rational r ( 1, 1 );
        AssertEqual ( 1, r.Numerator(), "1/1 const numerator" );
        AssertEqual ( 1, r.Denominator(), "1/1  const denominator" );
    }
    {
        Rational r ( 3, 9 );
        AssertEqual ( 1, r.Numerator(), "3/9 const numerator" );
        AssertEqual ( 3, r.Denominator(), "3/9  const denominator" );
    }
    {
        Rational r ( -1, -1 );
        AssertEqual ( 1, r.Numerator(), "-1/-1 const numerator" );
        AssertEqual ( 1, r.Denominator(), "-1/-1  const denominator" );
    }
    
    {
        Rational r ( -3, -9 );
        AssertEqual ( 1, r.Numerator(), "-3/-9 const numerator" );
        AssertEqual ( 3, r.Denominator(), "-3/-9  const denominator" );
    }
}

void Negative()
{
    {
        Rational r ( -1, 1 );
        AssertEqual ( -1, r.Numerator(), "-1/1 const numerator" );
        AssertEqual ( 1, r.Denominator(), "-1/1  const denominator" );
    }
    {
        Rational r ( 1, -1 );
        AssertEqual ( -1, r.Numerator(), "1/-1 const numerator" );
        AssertEqual ( 1, r.Denominator(), "1/-1  const denominator" );
    }
    
    {
        Rational r ( -3, 9 );
        AssertEqual ( -1, r.Numerator(), "-3/9 const numerator" );
        AssertEqual ( 3, r.Denominator(), "-3/9  const denominator" );
    }
    
    {
        Rational r ( 3, -9 );
        AssertEqual ( -1, r.Numerator(), "3/-9 const numerator" );
        AssertEqual ( 3, r.Denominator(), "3/-9  const denominator" );
    }
}
int main()
{
    TestRunner runner;
    runner.RunTest ( Default, "Default" );
    runner.RunTest ( Positive, "Positive" );
    runner.RunTest ( Negative, "Negative" );
    // Ð´Ð¾Ð±Ð°Ð²ÑŒÑ‚Ðµ ÑÑŽÐ´Ð° ÑÐ²Ð¾Ð¸ Ñ‚ÐµÑÑ‚Ñ‹
    return 0;
}
