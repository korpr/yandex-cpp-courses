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
            throw invalid_argument ( "Invalid argument" );
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
        throw domain_error ( "Invalid argument" );
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

class Operation
{
private:
    char op;
public:
    Operation ( char anOp = 0 ) : op ( anOp ) {};
    Rational Apply ( const Rational& arg1, const Rational& arg2 )
    {
        switch ( op ) {
        case '/' :
            if ( !arg2.Numerator() ) {
                throw domain_error ( "Division by zero" );
            }
            return arg1 / arg2;
        case '*':
            return arg1 * arg2;
        case '-':
            return arg1 - arg2;
        case '+':
            return arg1 + arg2;
        default:
            throw domain_error ( "" );
        }
    }
};
istream& operator>> ( istream& is, Operation& o )
{
    if ( !is ) {
        return is;
    }
    char op;
    is >> op;
    o = {op};
    return is;
}
int main()
{
    Rational arg1;
    Rational arg2;
    Operation op;
    try {
        cin >> arg1 >> op >> arg2;
        cout << op.Apply ( arg1, arg2 );
    } catch ( const exception& e ) {
        cout << e.what();
    }
    return 0;
}
