#include <iostream>

int main(int argc, char **argv)
{
    int a = 0;
    int b = 0;
    std::cin >> a >> b;
    for(; a <= b; ++a) {
        if (a % 2 == 0) {
            std::cout << a << " ";
        }
    }
    return 0;
}
