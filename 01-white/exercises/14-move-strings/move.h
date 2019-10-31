#include <vector>
#include <string>

void MoveStrings ( std::vector<std::string>& source, std::vector<std::string>& destination )
{
    destination.insert ( destination.end(), source.begin(), source.end() );
    source.clear();
}
