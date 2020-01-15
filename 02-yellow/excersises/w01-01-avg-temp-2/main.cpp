#include <iostream>
#include <vector>

int main ( int argc, char **argv )
{
    int n = 0;
    std::cin >> n;
    std::vector<int> temps ( n );
    int sum {0};
    for ( auto& t : temps ) {
        std::cin >> t;
        sum += t;
    }
    int avg {sum / n};
    
    std::vector<size_t> idxs;
    size_t count {0};
    for ( size_t idx {0}; idx < n; ++idx ) {
        if ( temps[idx]  > avg ) {
            ++count;
            idxs.push_back ( idx );
        }
    }
    std::cout << count << std::endl;
    
    for ( const auto& idx : idxs ) {
        std::cout << idx << " ";
    }
    
    std::cout << std::endl;
    return 0;
}
