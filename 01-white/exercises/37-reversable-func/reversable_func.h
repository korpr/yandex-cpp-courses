#include <vector>
#include <algorithm>

using namespace std;

using namespace std;

class FunctionPart
{
private:
    char op;
    double arg;
public:
    explicit FunctionPart ( const char& anOp, const double& anArg ) : op ( anOp ), arg ( anArg ) {}
    double Apply ( const double& exArgs ) const
    {
        if ( op == '-' ) {
            return exArgs + arg;
        } else {
            return exArgs - arg;
        }
    }
    void Invert()
    {
        if ( op == '-' ) {
            op = '+';
        } else {
            op = '-';
        }
    }
};

class Function
{
private:
    vector<FunctionPart> parts;
public:
    double Apply (  double arg ) const
    {
    
        for ( const auto& part : parts ) {
            arg = part.Apply ( arg );
        }
        return arg;
    }
    void Invert()
    {
        reverse ( begin ( parts ), end ( parts ) );
        for (  auto& part : parts ) {
            part.Invert();
        }
    }
    void AddPart ( const char& op, const double& arg )
    {
        parts.push_back ( FunctionPart ( op, arg ) );
    }
};
