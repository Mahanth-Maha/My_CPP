#include <iostream>

#define p(m) std::cout << m << std::endl;

int main() {
	//p("hello")
	// Using pointer instead of var
	int var = 44;
	int* ptr = &var;
	p(*ptr)
	// Allocating memory

	char* buff = new char[8];
	memset(buff, 0, 1);
	buff[0] = 'm';
	p(*buff);
	delete[] buff;
}