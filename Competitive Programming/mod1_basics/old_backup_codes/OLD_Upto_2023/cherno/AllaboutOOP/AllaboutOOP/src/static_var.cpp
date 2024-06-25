/*
* STATIC 
* 
* if declared out side a class :
*     it is avaliable in entire translational unit 
* else if declared in side a class :
*     it is avaliable in only that class
* 
* STATIC methods cannot access non static vars of class
*/
#include <iostream>

#define p(m) std::cout << m << std::endl;


class Sc {
public:
	static int sema;
};

int Sc::sema;

void smain(void) {
	Sc s;
	s.sema = 2;
	p(s.sema);
	Sc s2;
	s2.sema = 9;
	p(s.sema);
	p(s2.sema);
	//simply
	Sc::sema = 4;
	p(s.sema);
	p(s2.sema);
}