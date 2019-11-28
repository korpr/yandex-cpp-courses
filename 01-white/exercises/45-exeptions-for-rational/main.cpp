#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <map>
using namespace std;
class Rational
{
public:

    Rational ( int aNumerator = 0, int aDenominator = 1 )
    {
        if ( !aDenominator ) {
            throw invalid_argument ( "zero denominator" );
        }
        if ( !aNumerator ) {
            numerator = 0;
            denominator = 1;
        } else {
            int common  = gcd ( aNumerator, aDenominator );
            numerator = aNumerator / common;
            denominator = aDenominator / common;
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
    if ( !rhs.Numerator() ) {
        throw domain_error ( "zero division" );
    }
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

int main()
{
    try {
        Rational r ( 1, 0 );
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch ( invalid_argument& ) {
    }
    
    try {
        auto x = Rational ( 1, 2 ) / Rational ( 0, 1 );
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch ( domain_error& ) {
    }
    
    cout << "OK" << endl;
    return 0;
}
