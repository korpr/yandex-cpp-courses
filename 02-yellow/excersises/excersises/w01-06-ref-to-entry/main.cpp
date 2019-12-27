#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream& operator >> ( istream& is, Query& q )
{
    string type;
    is >> type;
    if ( "NEW_BUS" == type ) {
        q.type = QueryType:: NewBus;
        is >> q.bus;
        size_t count {0};
        is >> count;
        q.stops.resize ( count );
        for ( auto& stop : q.stops ) {
            is >> stop;
        }
    } else if ( "BUSES_FOR_STOP" == type ) {
        q.type = QueryType::BusesForStop;
        is >> q.stop;
    } else if ( "STOPS_FOR_BUS" == type ) {
        q.type = QueryType::StopsForBus;
        is >> q.stop;
    } else if ( "ALL_BUSES" == type ) {
        q.type = QueryType::AllBuses;
    }
    return is;
}

struct BusesForStopResponse {
    BusesForStopResponse() {};
    BusesForStopResponse ( vector<string> newBuses ) : buses ( newBuses ) {};
    vector<string> buses;
};

ostream & operator << ( ostream & os, const BusesForStopResponse & r )
{

    if ( r.buses.size() == 0 ) {
        os << "No stop";
    } else {
        for ( const string& bus : r.buses ) {
            os << bus << " ";
        }
    }
    return os;
}

struct StopsForBusResponse {
    string bus;
    vector < pair < string, vector<string>>> stops;
};

ostream& operator << ( ostream& os, const StopsForBusResponse& r )
{
    if ( r.stops.size() == 0 ) {
        os << "No bus";
    } else {
        for ( const auto& stop : r.stops ) {
            os << "Stop " << stop.first << ": ";
            if ( stop.second.size() <= 1 ) {
                os << "no interchange";
            } else {
                for ( const string& other_bus : stop.second ) {
                    if ( r.bus != other_bus ) {
                        os << other_bus << " ";
                    }
                }
            }
            os << endl;
        }
    }
    return os;
};
struct AllBusesResponse {
    map<string, vector<string>> buses_to_stops;
};

ostream& operator << ( ostream & os, const AllBusesResponse & r )
{

    if ( r.buses_to_stops.empty() ) {
        os << "No buses";
    } else {
        for ( const auto& bus_item : r.buses_to_stops ) {
            os << "Bus " << bus_item.first << ": ";
            for ( const string& stop : bus_item.second ) {
                os << stop << " ";
            }
            os << endl;
        }
    }
    return os;
}

class BusManager
{
private:
    map<string, vector<string>> buses_to_stops, stops_to_buses;
public:
    void AddBus ( const string& bus, const vector<string>& stops )
    {
        for ( const string& stop : stops ) {
            buses_to_stops[bus].push_back ( stop );
            stops_to_buses[stop].push_back ( bus );
        }
    }
    
    BusesForStopResponse GetBusesForStop ( const string& stop ) const
    {
        if ( stops_to_buses.count ( stop ) == 0 ) {
            return BusesForStopResponse();
        }
        return {stops_to_buses.at ( stop ) };
    }
    
    StopsForBusResponse GetStopsForBus ( const string& bus ) const
    {
        vector < pair < string, vector<string>>> stops;
        
        if ( buses_to_stops.count ( bus ) > 0 ) {
            for ( const auto& stop : buses_to_stops.at ( bus ) ) {
                stops.push_back ( make_pair ( stop, stops_to_buses.at ( stop ) ) );
            }
        }
        return {bus, stops};
    }
    
    AllBusesResponse GetAllBuses() const
    {
        return {buses_to_stops};
    }
};

int main()
{
    int query_count;
    Query q;
    
    cin >> query_count;
    
    BusManager bm;
    for ( int i = 0; i < query_count; ++i ) {
        cin >> q;
        switch ( q.type ) {
        case QueryType::NewBus:
            bm.AddBus ( q.bus, q.stops );
            break;
        case QueryType::BusesForStop:
            cout << bm.GetBusesForStop ( q.stop ) << endl;
            break;
        case QueryType::StopsForBus:
            cout << bm.GetStopsForBus ( q.bus ) << endl;
            break;
        case QueryType::AllBuses:
            cout << bm.GetAllBuses() << endl;
            break;
        }
    }
    
    return 0;
}
