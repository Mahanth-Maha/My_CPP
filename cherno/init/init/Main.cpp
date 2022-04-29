#include <iostream>

double mypow(double x,double y) {
	double sol = 1;
	for (double i = 0; i < y; i = i+1) sol *= x;
	return sol;
}

int main() {
	double s = mypow(2, 10);
	std::cout << "Hello There !" << std::endl ;
	std::cout << s << std::endl;
	std::cin.get();
}