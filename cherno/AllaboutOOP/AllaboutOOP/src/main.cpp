#include <iostream>

#define p(m) std::cout << m << std::endl;

int lmain(void);
int l2main(void);
void smain(void);


//A Class is private by default
class Player {
	int x, y, speed;
};

// public: is used to specify them as public
class Player2 {
public:
	int x, y, speed;

	void move(int xa,int ya) {
		x += xa * speed;
		y += ya * speed;
	}
	void d() {
		p(x);
		p(y);
		p(speed);
	}
};

// A Struct is similar to class 99% except it is public by default ! can change to private same as class with private keyword

// COMPATIBILITY ISSUES

struct Player3 {
	int x, y, speed;

	void d() {
		p(x);
		p(y);
		p(speed);
	}
private:
	void move(int xa, int ya) {
		x += xa * speed;
		y += ya * speed;
	}

};

int main() {
	p("Object Oriented Programming");
	Player p1;
	// p1.x = 5;  //"""Cant do this since the variables in Player is private made it public in Player 2"""
	Player2 p2;
	p2.x = 5;
	p2.y = 10;
	p2.speed = 2;
	//  methods ......
	p2.d();
	p2.move(1, 2);
	p2.d();
	//struct vs class
	Player3 p3;
	p3.x = 3;
	p3.y = -2;
	p3.speed = 1;
	p3.d();
	//p3.move(3,4);  //"""Cant do this since the variables in Player is  public made it private  in Player 3"""

	/*
	* USE struct for 1 level 
	* USE class for inheritance or multi level !
	*/
	p("");
	//lmain();
	//smain();
	l2main();
}