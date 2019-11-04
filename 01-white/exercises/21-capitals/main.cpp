#include <iostream>
#include <string>
#include <map>
using namespace std;

int main ( int argc, char **argv )
{
    size_t n = 0;
    std::cin >> n;
    map<string, string> country_capital;
    string command;
    for ( size_t i = 0; i < n; ++i ) {
        cin >> command;
        if ( "CHANGE_CAPITAL" == command ) {
            string country;
            string new_capital;
            cin >> country >> new_capital;
            string old_capital = country_capital[country];
            if ( old_capital.empty() ) {
                cout << "Introduce new country " << country << " with capital " << new_capital;
            } else if ( old_capital == new_capital ) {
                cout << country << " country hasn't changed its capital";
            } else {
                cout << country << " country has changed its capital from " << old_capital << " to " << new_capital;
            }
            country_capital[country] = new_capital;
            
        } else if ( "RENAME" == command ) {
            string old_country_name;
            string new_country_name;
            cin >> old_country_name >> new_country_name;
            if ( new_country_name == old_country_name || !country_capital.count ( old_country_name ) || country_capital.count ( new_country_name ) ) {
                cout << "Incorrect rename, skip";
            } else {
                string capital = country_capital[old_country_name];
                country_capital.erase ( old_country_name );
                country_capital[new_country_name] = capital;
                cout << "Country" << old_country_name << " with capital " << capital << " has been renamed to " << new_country_name;
            }
            
        } else if ( "ABOUT" == command ) {
            string country_name;
            cin >> country_name ;
            if ( country_capital.count ( country_name ) ) {
                cout << "Country " << country_name << " has capital " << country_capital[country_name];
            } else {
                cout << "Country " << country_name << " doesn't exist";
            }
        } else if ( "DUMP" == command ) {
            if ( country_capital.size() ) {
                for ( const auto& pair : country_capital ) {
                    cout << pair.first << "/" << pair.second << " ";
                }
                
            } else {
                cout << "There are no countries in the world";
            }
        }
        
        cout << endl;
    }
    return 0;
}
