#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    std::string text;
    std::cin >> text;
    int occurrence = -2;
    size_t idx = 0;
    for(; idx < text.size(); ++idx) {
        if (text[idx] == 'f') {
            occurrence++;
        }
        if (occurrence == 0) {
            occurrence = idx;
            break;
        }
    }
    std::cout << occurrence;
    return 0;
}
