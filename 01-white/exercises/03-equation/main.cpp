#include <iostream>
#include <cmath>

int main(int argc, char **argv)
{
	double a{0};
	double b{0};
	double c{0};
	std::cin >> a >> b >> c;
	double d = std::pow(b,2) - 4*a*c;
	if (d < 0) {
		//no solution
		return 0;
	}

	double sqrtD {std::sqrt(d)};
	double v1 = -(b + sqrtD)/(2*a);
	double v2 = -(b - sqrtD)/(2*a);

	std::cout << v1;
	if (v1 != v2) {
		std::cout << " " << v2;
	}
	return 0;
}
