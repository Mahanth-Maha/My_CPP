#include <iostream>

#define p(m) std::cout << m << std::endl;

void incr_ptr(int* value) {
	(*value)++;
}
//cleaner compared to above
void incr_ref(int& value) {
	value++;
}

int main() {
	//p("hello")
	// Using pointer instead of var
	int var = 44;
	int* ptr = &var;
	p(*ptr)

    // references
	int& ref = var;
	//once ref is set we cant change it ( no re assign this to new var ref)
	int newvar = 12;
	ref = newvar;
	// Allocating memory

	char* buff = new char[8];
	memset(buff, 0, 1);
	buff[0] = 'm';
	p(*buff);
	delete[] buff;

	// Pass by reference 2 ways
	p(var);
	incr_ptr(&var);
	p(var);
	incr_ref(var);
	p(var);
}