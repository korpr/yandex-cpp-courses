#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void add_affair ( vector<vector<string>>& affairs );
void copy ( vector<vector<string>>& affairs, size_t new_days_count );
void dump ( const vector<vector<string>>& affairs );
size_t read_day ();
const vector<size_t> days_in_month =
{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int MONTH_COUNT = 12;
int main ( int argc, char **argv )
{

    size_t current_month = 0;
    int n = 0;
    std::cin >> n;
    vector<vector<string>> monthly_affairs ( days_in_month[current_month] );
    string command;
    for ( size_t idx = 0; idx < n; ++idx ) {
        cin >> command;
        if ( command == "ADD" ) {
            add_affair ( monthly_affairs );
        } else if ( command == "NEXT" ) {
            copy ( monthly_affairs, days_in_month[ ( ++current_month ) % MONTH_COUNT] );
        } else if ( command == "DUMP" ) {
            dump ( monthly_affairs );
            cout << endl;
        }
    }
    return 0;
}


void add_affair ( vector<vector<string>>& affairs )
{
    size_t day = read_day();
    string affair;
    cin >> affair;
    if ( affairs[day].end() == find ( affairs[day].begin(), affairs[day].end(), affair ) ) {
        affairs[day].push_back ( affair );
    }
}
void copy ( vector<vector<string>>& affairs, size_t new_days_count )
{
    if ( new_days_count < affairs.size() ) {
        auto& last_day_affairs =  affairs[new_days_count - 1];
        for ( int idx = new_days_count; idx < affairs.size(); ++idx ) {
            last_day_affairs.insert ( end ( last_day_affairs ), begin ( affairs[idx] ), end ( affairs[idx] ) );
        }
    }
    affairs.resize ( new_days_count );
}
void dump ( const vector<vector<string>>& affairs )
{
    size_t day = read_day();
    cout << affairs[day].size();
    for ( auto& el : affairs[day] ) {
        cout << " " << el;
    }
}

size_t read_day()
{
    size_t day = 0;
    cin >> day;
    return --day;
}
