#include <map>
#include <set>
#include <string>

std::set<std::string> BuildMapValuesSet ( const std::map<int, std::string>& m )
{
    std::set<std::string> result;
    
    for ( const auto& pair : m ) {
        result.insert ( pair.second );
    }
    
    return result;
}
