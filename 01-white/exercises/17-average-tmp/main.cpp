#include <iostream>
#include <vector>



int main ( int argc, char **argv )
{
    int n = 0;
    std::cin >> n;
    if ( n < 1 ) {
        return 0;
    }
    std::vector<int> temp ( n );
    int sum = 0;
    for ( auto& el : temp ) {
        std::cin >> el;
        sum += el;
    }
    
    int avg = sum / n;
    std::vector<size_t> idxs;
    for ( size_t idx = 0; idx < n; ++idx ) {
        if ( temp[idx] > avg ) {
            idxs.push_back ( idx );
        }
    }
    std::cout << idxs.size() << std::endl;
    for ( auto& el : idxs ) {
        std::cout << el << " ";
    }
    return 0;
}
