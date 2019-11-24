#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
struct Year {
    explicit Year ( size_t aValue ) : value ( aValue ) {}
    size_t value;
};

struct Month {
    explicit Month ( size_t aValue ) : value ( aValue ) {}
    size_t value;
};

struct Day {
    explicit Day ( size_t aValue ) : value ( aValue ) {}
    size_t value;
};
struct Date {
    explicit Date ( Year aYear, Month aMonth, Day aDay ) : year ( aYear ), month ( aMonth ), day ( aDay ) {}
    Year year;
    Month month;
    Day day;
};

struct Name {
    explicit Name ( string aValue ) : value ( aValue ) {};
    string value;
};

struct Surname {
    explicit Surname ( string aValue ) : value ( aValue ) {};
    string value;
};
struct Student {
    Name name;
    Surname surname;
    Date birth_date;
    string full_name()
    {
        stringstream s;
        s << name.value << " " << surname.value;
        return s.str();
    }
    string birth_date_as_string()
    {
        stringstream s;
        s << birth_date.day.value << "." <<  birth_date.month.value << "." <<  birth_date.year.value;
        return s.str();
    }
};

int main ( int argc, char **argv )
{
    size_t list_length  {0};
    cin >> list_length;
    vector<Student> students ;
    string f_name;
    string l_name;
    size_t year {0}, month{0}, day{0};
    
    for ( size_t i{0}; i < list_length; ++i ) {
        cin >> f_name >> l_name >> day >> month >> year;
        students.push_back ( {Name ( f_name ), Surname ( l_name ), Date ( Year{year}, Month ( month ), Day ( day ) ) } );
    }
    
    size_t request_count {0};
    cin >> request_count;
    string command;
    size_t idx;
    for ( size_t i{0}; i < request_count; ++i ) {
        cin >> command >> idx;
        --idx;
        if ( idx < list_length && command == "name"  ) {
            cout << students[idx].full_name();
        } else if ( idx < list_length && command == "date" ) {
            cout <<  students[idx].birth_date_as_string();
        } else {
            cout << "bad request";
        }
        cout << endl;
    }
    return 0;
}
