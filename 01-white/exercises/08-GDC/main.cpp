#include <iostream>

int main ( int argc, char **argv )
{
    int a = 0;
    int b = 0;
    std::cin >> a >> b;
    int arg1 = a;
    int arg2 = b;
    while ( arg2 != 0 ) {
        int temp = arg1 % arg2;
        arg1 = arg2;
        arg2 = temp;
    }
    std::cout << arg1;
    return 0;
}
