#include <iostream>
#include <string>

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
}

int main ( int argc, char **argv )
{
    std::string a;
    std::cin >> a;
    std::cout << std::boolalpha << IsPalindrom ( a );
    return 0;
}
