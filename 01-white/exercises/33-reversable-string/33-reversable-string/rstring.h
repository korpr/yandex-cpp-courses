#include <string>
#include <algorithm>
using namespace std;

class ReversibleString
{
private:
    string str;
    
public:


    ReversibleString ( string aString = "" ) : str ( aString )
    {
    
    }
    void Reverse()
    {
        reverse ( begin ( str ), end ( str ) );
    }
    
    string ToString() const
    {
        return str;
    }
};
