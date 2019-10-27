#include <iostream>

int main(int argc, char **argv)
{
    int a = 0;
    int b = 0;
    std::cin >> a >> b;
    if (b == 0) {
        std::cout << "Impossible";
    } else {
        std::cout << a / b;
    }

    return 0;
}
