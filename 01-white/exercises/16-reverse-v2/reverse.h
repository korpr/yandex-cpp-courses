#include <vector>

std::vector<int> Reversed ( const std::vector<int>& v )
{
    std::vector<int> reversed;
    for ( auto it = v.rbegin(); it < v.rend(); ++it ) {
        reversed.push_back ( *it );
    }
    return reversed;
}
