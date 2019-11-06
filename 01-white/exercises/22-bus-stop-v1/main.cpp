#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

enum ECommand {NEW_BUS, BUSES_FOR_STOP, STOPS_FOR_BUS, ALL_BUSES, NONE};
const map<string, ECommand> COMMANDS_MAP = {
    {"NEW_BUS", ECommand::NEW_BUS},
    {"BUSES_FOR_STOP", ECommand::BUSES_FOR_STOP},
    {"STOPS_FOR_BUS", ECommand::STOPS_FOR_BUS},
    {"ALL_BUSES", ECommand::ALL_BUSES}
};

ECommand read_command ( istream& is )
{
    string command;
    is >> command;
    if ( COMMANDS_MAP.find ( command ) == end ( COMMANDS_MAP ) ) {
        return ECommand::NONE;
    }
    return COMMANDS_MAP.at ( command );
};
void add_busses ( istream& is,
                  map<string, vector<string>>& buses,
                  map<string, vector<string>>& stops )
{
    string bus;
    int stop_count;
    is >> bus >> stop_count;
    vector<string>& stops_for_bus = buses[bus];
    stops_for_bus.resize ( stop_count );
    for ( auto& stop :  stops_for_bus ) {
        is >> stop;
        stops[stop].push_back ( bus );
    }
};
void buses_for_stop ( istream& is, ostream& os, const map<string, vector<string>>& stops )
{
    string stop;
    is >> stop;
    if ( stops.find ( stop ) == end ( stops ) ) {
        os << "No stops\n";
        return;
    }
    for ( const auto& bus : stops.at ( stop ) ) {
        os << bus << " ";
    }
    os << endl;
};
void stop_for_buses ( istream& is, ostream& os,
                      const map<string, vector<string>>& buses,
                      const map<string, vector<string>>& stops )
{
    string bus;
    is >> bus;
    if ( buses.find ( bus ) == end ( buses ) ) {
        os << "No bus\n";
        return;
    }
    
    for ( const auto& stop : buses.at ( bus ) ) {
        os << "Stop " << stop << " : ";
        if ( stops.at ( stop ).size()  == 1 ) {
            os << "no interchange\n";
        } else {
            for ( const auto& bus_for_stop : stops.at ( stop ) ) {
                if ( bus_for_stop != bus ) {
                    os << bus_for_stop << " ";
                }
            }
            os << endl;
        }
        
    }
}


void all_buses (
    ostream& os,
    const map<string, vector<string>>& buses )
{
    if ( buses.empty() ) {
        os << "No buses\n" ;
        return;
    }
    for ( const auto& bus : buses ) {
        os << "Bus " << bus.first << ": ";
        for ( const auto& s : bus.second ) {
            os << s << " ";
        }
        os << endl;
    }
};
int main ( int argc, char **argv )
{

    map<string, vector<string>> buses;
    map<string, vector<string>> stops;
    int n = 0;
    cin >> n;
    for ( int i = 0; i < n; ++i ) {
        ECommand command = read_command ( cin );
        switch ( command ) {
        case NEW_BUS:
            add_busses ( cin, buses, stops );
            break;
        case BUSES_FOR_STOP:
            buses_for_stop ( cin, cout, stops );
            break;
        case STOPS_FOR_BUS:
            stop_for_buses ( cin, cout, buses, stops );
            break;
        case ALL_BUSES:
            all_buses ( cout, buses );
            break;
        case NONE:
            break;
        }
    }
    return 0;
}
