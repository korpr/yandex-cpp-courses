#include <iostream>
#include "update.h"

int main ( int argc, char **argv )
{
    int a = 0;
    int b = 0;
    std::cin >> a >> b;
    UpdateIfGreater ( a, b );
    std::cout << b;
    return 0;
}
