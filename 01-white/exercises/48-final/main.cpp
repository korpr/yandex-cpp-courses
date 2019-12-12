#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iomanip>

using namespace std;
// Реализуйте функции и методы классов и при необходимости добавьте свои
class format_error : public runtime_error
{
public:
    explicit format_error ( const string& what_arg ) : runtime_error ( what_arg ) {};
    explicit format_error ( const char* what_arg ) : runtime_error ( what_arg ) {}
};
class Date
{
public:
    Date ( int aYear = 0, int aMonth = 0, int aDay = 0 )
    {
        //Month value is invalid: MONTH -1 13
        if ( aMonth < 1 || aMonth > 12 ) {
            stringstream ss;
            ss << "Month value is invalid: " << aMonth;
            throw invalid_argument ( ss.str() );
        }
        //«Day value is invalid: DAY», где DAY — это неверный номер дня в месяце, например, 39 или 0.
        if ( aDay < 1 || aDay > 31 ) {
            stringstream ss;
            ss << "Day value is invalid: " << aDay;
            throw invalid_argument ( ss.str() );
        }
        
        year = aYear;
        month = aMonth;
        day = aDay;
    }
    int GetYear() const
    {
        return year;
    }
    int GetMonth() const
    {
        return month;
    }
    int GetDay() const
    {
        return day;
    }
private:
    int year;
    int month;
    int day;
};

bool operator< ( const Date & lhs, const Date & rhs )
{
    vector<int> vlhs {lhs.GetYear(), lhs.GetMonth(), lhs.GetDay() };
    vector<int> vrhs {rhs.GetYear(), rhs.GetMonth(), rhs.GetDay() };
    return vlhs < vrhs;
}

ostream& operator<< ( ostream& os, const Date& date )
{
    os << setw ( 4 ) << setfill ( '0' ) << date.GetYear() << '-' << setw ( 2 ) << setfill ( '0' ) << date.GetMonth() << '-' << setw ( 2 ) << setfill ( '0' ) << date.GetDay();
    return os;
}

Date ParseDate ( const string& date_string )
{
    istringstream date_stream ( date_string );
    bool no_error {true};
    
    int year {0};
    
    no_error = no_error && ( date_stream >> year );
    no_error = no_error && ( '-' == date_stream.peek() );
    date_stream.ignore ( 1 );
    
    int month{0};
    no_error =  no_error && ( date_stream >> month );
    no_error =  no_error && ( '-' == date_stream.peek() );
    date_stream.ignore ( 1 );
    
    int day{0};
    no_error =  no_error && ( date_stream >> day );
    no_error =  no_error && ( date_stream.eof() );
    
    if ( !no_error ) {
        throw runtime_error ( "wrong date format: " + date_string );
    }
    
    return {year, month, day};
}

class Database
{
public:
    void AddEvent ( const Date & date, const string & event )
    {
        events[date].insert ( event );
    };
    bool DeleteEvent ( const Date & date, const string & event )
    {
        return events.count ( date ) && events[date].erase ( event );
    }
    int  DeleteDate ( const Date & date )
    {
        if ( events.count ( date ) ) {
            int size = events[date].size();
            events.erase ( date );
            return size;
        }
        return 0;
    }
    
    set<string> Find ( const Date & date ) const
    {
        if ( events.count ( date ) ) {
            return events.at ( date );
        }
        return {};
    }
    
    void Print() const
    {
        for ( const auto& row : events ) {
            for ( const string& event : row.second ) {
                cout << row.first << " " << event << endl;
            }
        };
    }
private:
    map<Date, set<string>> events;
};

int main()
{
    Database db;
    
    string command;
    try {
        while ( getline ( cin, command ) ) {
            istringstream ss ( command );
            string operation;
            ss >> operation;
            if ( "Add" == operation ) {
                string date_string, event;
                ss >> date_string >> event;
                Date date = ParseDate ( date_string );
                db.AddEvent ( date, event );
                
            } else if ( "Del" == operation ) {
                string date_string, event;
                ss >> date_string >> event;
                Date date = ParseDate ( date_string );
                if ( event.empty() ) {
                    cout << "Deleted " << db.DeleteDate ( date ) << " events" << endl;
                } else {
                    if ( db.DeleteEvent ( date, event ) ) {
                        cout << "Deleted successfully" << endl;
                    } else {
                        cout << "Event not found" << endl;
                    }
                }
            } else if ( "Find" == operation ) {
                string date_str;
                ss >> date_str;
                const Date date = ParseDate ( date_str );
                for ( const string& event : db.Find ( date ) ) {
                    cout << event << endl;
                }
            } else if ( "Print" == operation ) {
                db.Print();
            } else if ( !operation.empty() ) {
                throw logic_error ( "Unknown command: " + command );
            }
            
        }
    } catch ( const exception &e ) {
        cout << e.what() << endl;
    }
    return 0;
}
