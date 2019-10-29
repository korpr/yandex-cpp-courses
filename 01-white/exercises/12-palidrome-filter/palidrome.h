#include <iostream>
#include <string>
#include <vector>

bool IsPalindrom ( std::string& text )
{
    size_t lastElem = text.size() - 1;
    size_t center = text.size() / 2 ;
    for ( size_t idx = 0; idx <  center ; ++idx ) {
        if ( text[idx] != text[lastElem - idx] ) {
            return false;
        }
    }
    return true;
};

std::vector<std::string> PalindromFilter ( std::vector<std::string> words, int min_lengths )
{
    std::vector<std::string> result;
    for ( auto& word : words ) {
        if ( word.size() >= min_lengths && IsPalindrom ( word ) ) {
            result.push_back ( word );
        }
    }
    return result;
};
