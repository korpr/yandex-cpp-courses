#include <iostream>

int Factorial ( int for_number )
{
    if ( for_number < 2 ) {
        return 1;
    }
    
    return for_number * Factorial ( for_number - 1 );
}
int main ( int argc, char **argv )
{
    int a = 0;
    std::cin >> a;
    std::cout << Factorial ( a );
    return 0;
}
