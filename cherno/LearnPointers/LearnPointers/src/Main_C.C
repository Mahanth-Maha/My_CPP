/*
#include <stdio.h>

#define p(m) printf("%d\n",m);

void incr_ptr(int* value) {
	(*value)++;
}

void incr_ref(int& value) {
	value++;
}

int main() {
	//p("hello")
	// Using pointer instead of var
	int var = 44;
	int* ptr = &var;
	p(*ptr)
		// Allocating memory

	//char* buff = new char[8];
	//memset(buff, 0, 1);
	//buff[0] = 'm';
	//p(*buff);
	//delete[] buff;

	// Pass by reference 2 ways
	p(var);
	incr_ptr(&var);
	p(var);
	incr_ref(var);
	p(var);
}
*/