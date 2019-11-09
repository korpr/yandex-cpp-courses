#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;
int synonymsCount ( const map<string, set<string>>& synomyms, const string& synomyn );
void add ( map < string, set<string>>& synonyms, string w1, string w2 );
bool check ( const map < string, set<string>>& synonyms, const string& w1, const string& w2 );

int main ( int argc, char **argv )
{
    int q = 0;
    std::cin >> q;
    string command;
    map<string, set<string>> synonyms;
    for ( size_t i = 0 ; i < q; ++q ) {
        cin >> command;
        if ( "ADD" == command ) {
            string w1, w2;
            cin >> w1 >> w2;
            add ( synonyms, w1, w2 );
        } else if ( "CHECK" == command ) {
            string w1, w2;
            cin >> w1 >> w2;
            cout  << ( check ( synonyms, w1, w2 ) ? "YES" : "NO" ) << endl;
        } else if ( "COUNT" == command ) {
            string w1;
            cin >> w1;
            cout << synonymsCount ( synonyms, w1 ) << endl;
        }
        
    }
    return 0;
}
int synonymsCount ( const map<string, set<string>>& synomyms, const string& synonym )
{
    if ( synomyms.count ( synonym ) ) {
        return synomyms.at ( synonym ).size();
    }
    return 0;
}
void add ( map < string, set<string>>& synonyms, string w1, string w2 )
{
    synonyms[w1].insert ( w2 );
    synonyms[w2].insert ( w1 );
}
bool check ( const map < string, set<string>>& synonyms, const string& w1, const string& w2 )
{
    if ( synonymsCount ( synonyms, w1 ) ) {
        return synonyms.at ( w1 ).count ( w2 ) > 0;
    }
    return false;
};
