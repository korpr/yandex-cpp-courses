#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Person
{
public:


    void ChangeFirstName ( int year, const string& first_name )
    {
        first_names[year] = first_name;
    }
    void ChangeLastName ( int year, const string& last_name )
    {
        last_names[year] = last_name;
    }
    string GetFullName ( int year )
    {
        const string first_name = GetRecordForYear ( first_names, year );
        const string last_name = GetRecordForYear ( last_names, year ) ;
        
        if ( first_name.empty() && last_name.empty() ) {
            return "Incognito";
        } else if ( last_name.empty() ) {
            return  first_name + " with unknown first name";
        } else if ( first_name.empty() ) {
            return  last_name + " with unknown first name";
        } else {
            return first_name + " " + last_name;
        }
    }
    string GetFullNameWithHistory ( int year )
    {
        const vector<string> first_name = GetRecordForYearWH ( first_names, year );
        const vector<string> last_name = GetRecordForYearWH ( last_names, year ) ;
        
        if ( first_name.empty() && last_name.empty() ) {
            return "Incognito";
        } else if ( last_name.empty() ) {
            return  concat ( first_name ) + " with unknown first name";
        } else if ( first_name.empty() ) {
            return  concat ( last_name ) + " with unknown first name";
        } else {
            return concat ( first_name ) + " " + concat ( last_name );
        }
    }
private:
    map<int, string> first_names;
    map<int, string> last_names;
    string GetRecordForYear (  map<int, string> names, int year )
    {
        string result;
        for ( const auto& element : names ) {
            if ( element.first <= year ) {
                result = element.second;
            } else {
                break;
            }
        }
        return result;
    }
    
    string concat ( const vector<string>& names )
    {
        if ( names.empty() ) {
            return "";
        }
        if ( names.size () == 1 ) {
            return *names.rbegin();
        }
        
        string result =  *names.rbegin() + " (";
        for ( auto it = names.rbegin() + 1; it != names.rend(); ++it ) {
            result += *it;
            if ( it + 1 != names.rend() ) {
                result += ", ";
            }
        }
        result +=  ")";
        return result;
    }
    vector<string> GetRecordForYearWH (  map<int, string> names, int year )
    {
        vector<string> result;
        for ( const auto& element : names ) {
            if ( element.first <= year ) {
                result.push_back ( element.second );
            } else {
                break;
            }
        }
        return result;
    }
};
