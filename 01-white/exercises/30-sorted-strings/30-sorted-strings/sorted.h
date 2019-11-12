#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class SortedStrings
{
public:
    void AddString ( const string& s )
    {
        strs.push_back ( s );
    }
    vector<string> GetSortedStrings()
    {
        sort ( begin ( strs ), end ( strs ) );
        return strs;
    }
private:
    vector<string> strs;
};
