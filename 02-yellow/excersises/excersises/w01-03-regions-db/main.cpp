#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
enum class Lang {
    DE, FR, IT
};
struct Region {
    string std_name;
    string parent_std_name;
    map<Lang, string> names;
    int64_t population;
};


tuple<const string&, const string&, const map<Lang, string>&, const int64_t> doTie ( const Region& r )
{
    return tie ( r.std_name, r.parent_std_name, r.names, r.population ) ;
};
bool operator< ( const Region& lhs, const Region& rhs )
{
    return doTie ( lhs ) < doTie ( rhs );
};
int FindMaxRepetitionCount ( const vector<Region>& regions )
{
    map<Region, int> counter;
    int max_counter {0};
    for ( const auto& region : regions ) {
        max_counter = max ( ++counter[region], max_counter );
    }
    return max_counter;
};

int main ( int argc, char **argv )
{
    cout << FindMaxRepetitionCount ( {
        {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Russia",
            "Eurasia",
            {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
            89
        }, {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Russia",
            "Eurasia",
            {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
            89
        },
    } ) << endl;
    
    cout << FindMaxRepetitionCount ( {
        {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Russia",
            "Eurasia",
            {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
            89
        }, {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Moscow",
            "Toulouse",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            31
        },
    } ) << endl;
    
    return 0;
}
