#include <palidrome.h>
#include <vector>
/**
 *
 * abacaba, aba	5	abacaba
abacaba, aba	2	abacaba, aba
weew, bro, code	4	weew
 * @brief
 * @param argc
 * @param argv
 * @return
 */
int main ( int argc, char **argv )
{
    std::vector<std::string> v1 = {"abacaba", "aba"};
    for ( const auto& w : PalindromFilter ( v1, 5 ) ) {
        std::cout << w << " ";
    }
    std::cout << "\n2=";
    
    for ( const auto& w : PalindromFilter ( {"abacaba", "aba"}, 2 ) ) {
        std::cout << w << " ";
    }
    std::cout << "\n3=";
    
    for ( const auto& w : PalindromFilter ( {"weew", "bro", "code"}, 4 ) ) {
        std::cout << w << " ";
    }
    std::cout << "\n4=";
    
    for ( const auto& w : PalindromFilter ( {"weew", "bro", "code"}, 5 ) ) {
        std::cout << w << " ";
    }
    std::cout << "\n5=";
    
    for ( const auto& w : PalindromFilter ( {}, 5 ) ) {
        std::cout << w << " ";
    }
    std::cout << "\n";
    return 0;
}
