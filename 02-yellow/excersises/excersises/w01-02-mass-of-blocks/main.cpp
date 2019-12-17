#include <iostream>
#include <limits>
int main ( int argc, char **argv )
{
    uint N  {0};
    uint R {0};
    
    std::cin >> N >> R;
    uint64_t mass {0};
    
    for ( size_t idx {0}; idx < N; ++idx ) {
        int W{0};
        int H{0};
        int D{0};
        std::cin >> W >> H >> D;
        mass += static_cast<uint64_t> ( R ) * W * H * D;
    }
    std::cout << mass << std::endl;
    return 0;
}
