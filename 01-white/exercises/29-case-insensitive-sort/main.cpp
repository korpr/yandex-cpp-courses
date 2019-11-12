#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main ( int argc, char **argv )
{
    int n = 0;
    std::cin >> n;
    std::vector<std::string> strs ( n );
    
    for ( auto& str : strs ) {
        std::cin >> str;
    }
    
    std::sort ( std::begin ( strs ), std::end ( strs ), [] ( std::string f, std::string s ) {
        std::transform ( std::begin ( f ), std::end ( f ), std::begin ( f ), ::tolower );
        std::transform ( std::begin ( s ), std::end ( s ), std::begin ( s ), ::tolower );
        return f < s;
    } );
    
    for ( const auto& str : strs ) {
        std::cout << str << " ";
    }
    
    return 0;
}
