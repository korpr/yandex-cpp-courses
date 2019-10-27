#include <iostream>

int main(int argc, char **argv)
{
    double n = 0;
    double a = 0;
    double b = 0;
    double x = 0;
    double y = 0;
    std::cin >> n >> a >> b >> x >> y;
    double multiplayer = 1;
    if (n > b) {
        multiplayer -= y / 100;
    } else if (n > a) {
        multiplayer -= x / 100;
    }

    std::cout << n * multiplayer;
    return 0;
}
