#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Person
{

public:

    Person ( string first_name, string last_name, int year )
    {
        year_of_birth = year;
        first_names[year] = first_name;
        last_names[year] = last_name;
    }
    
    void ChangeFirstName ( int year, const string& first_name )
    {
        if ( IsBorn ( year ) ) {
            first_names[year] = first_name;
        }
    }
    void ChangeLastName ( int year, const string& last_name )
    {
        if ( IsBorn ( year ) ) {
            last_names[year] = last_name;
        }
    }
    string GetFullName ( int year ) const
    {
        if ( !IsBorn ( year ) ) {
            return NO_PERSON;
        }
        const string first_name = GetRecordForYear ( first_names, year );
        const string last_name = GetRecordForYear ( last_names, year ) ;
        return PrepareResponse ( first_name, last_name );
        
    }
    string GetFullNameWithHistory ( int year ) const
    {
        if ( !IsBorn ( year ) ) {
            return NO_PERSON;
        }
        
        const string first_name = concat ( GetRecordForYearWH ( first_names, year ) );
        const string last_name = concat ( GetRecordForYearWH ( last_names, year ) );
        
        return PrepareResponse ( first_name, last_name );
    }
private:
    const string INCOGNITO = "Incognito";
    const string NO_PERSON = "No person";
    
    map<int, string> first_names;
    map<int, string> last_names;
    int year_of_birth;
    
    
    bool IsBorn ( int year ) const
    {
        return year_of_birth <= year;
    }
    
    string PrepareResponse ( const string& f_name, const string& l_name ) const
    {
        if ( f_name.empty() && l_name.empty() ) {
            return INCOGNITO;
        } else if ( l_name.empty() ) {
            return  f_name + " with unknown first name";
        } else if ( f_name.empty() ) {
            return  l_name + " with unknown first name";
        } else {
            return f_name + " " + l_name;
        }
    }
    
    string GetRecordForYear (  map<int, string> names, int year ) const
    {
        const vector<string> variants = GetRecordForYearWH ( names, year );
        return variants.empty() ? "" : variants.back();
    }
    
    vector<string> GetRecordForYearWH (  map<int, string> names, int year ) const
    {
        vector<string> result;
        for ( const auto& element : names ) {
            if ( element.first > year ) {
                break;
            }
            result.push_back ( element.second );
        }
        return result;
    }
    
    string concat ( const vector<string>& names ) const
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
};
