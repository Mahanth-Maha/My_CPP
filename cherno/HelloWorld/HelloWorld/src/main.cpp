#include <iostream>

int mypow(int x, int y) {
	int sol = 1;
	for (int i = 0; i < y; i = i + 1) sol *= x;
	return sol;
}

int main() {
	int s = mypow(2, 10);
	std::cout << "Hello There !" << std::endl;
	std::cout << "\n\n2 ^ 10 = " << s << std::endl;
	std::cout << "The memory sizes of\n\nchar\t\t" << sizeof(char) << "\nshort\t\t" << sizeof(short) << "\nint\t\t" << sizeof(int);
	std::cout << "\nlong\t\t" << sizeof(long) << "\nlong long\t" << sizeof(long long) << "\nfloat\t\t" << sizeof(float) << "\ndouble\t\t" << sizeof(double);
	std::cin.get();
}