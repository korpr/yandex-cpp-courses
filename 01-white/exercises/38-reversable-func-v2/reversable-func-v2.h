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
    FunctionPart (  char anOp,  double anArg ) : op ( anOp ), arg ( anArg ) {}
    double Apply ( const double& exArgs ) const
    {
        switch ( op ) {
        case '+':
            return exArgs + arg;
            break;
        case '-':
            return exArgs - arg;
            break;
        case '*':
            return exArgs * arg;
            break;
        case '/':
            return exArgs / arg;
            break;
        default:
            return 0;
        }
    }
    void Invert()
    {
        switch ( op ) {
        case '+':
            op = '-';
            break;
        case '-':
            op = '+';
            break;
        case '*':
            op = '/';
            break;
        case '/':
            op = '*';
            break;
        default:
            return ;
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
    void AddPart (  char op,  double arg )
    {
        parts.push_back ( {op, arg } );
    }
};
