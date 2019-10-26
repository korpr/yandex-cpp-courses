#include <iostream>
#include <string>
int main(int argc, char **argv)
{
	std::string current_min;
	std::string candidate;
	std::cin >> current_min >> candidate;
	current_min = current_min < candidate ? current_min:candidate;
	std::cin>> candidate;
	current_min = current_min < candidate ? current_min:candidate;
	std::cout << current_min;
	return 0;
}
