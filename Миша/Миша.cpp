#include <iostream>
#include <utility>
#include "Rational.h"

void print(Rational& other);

int main()
{
	//Creat
	Rational r1 = new Rational{}; //0/1
	Rational r2 = new Rational{5}; //5/1
	Rational r3 = new Rational{3,4}; //3/4
	//converting back
	int a = r1.ToInt();			//0
	double b = r2.ToDouble();	//5.0
	//a/b => b/a
	r1 = r2.Inverse();			// 0/1 => 1/5
	print(r1);
	//Operation
	r1 = r2 + r3;				// 5/1 + 3/4 => 23/4
	print(r1);
	r1 = r2 - r3;				// 5/1 - 3/4 => 17/4
	print(r1);
	r1 = r2 * r3;				// 5/1 * 3/4 => 15/4
	print(r1);
	r1 = r2 / r3;				// 5/1 : 3/4 => 20/3
	print(r1);
	//additional reduction
	r1 = r2 + 1;				// 5/1 + 1 => 6/1
	print(r1);
	r1 = r2-1;					// 5/1 - 1 => 4/1
	print(r1);
	r1 = r2 *3;					// 5/1 * 3 => 15/1
	print(r1);
	r1 = r2 / 3;				// 5/1 : 3 => 5/3
	print(r1);
	
	return 0;
}

void print(Rational&other)
{
	std::cout << "Point : \n A:" << other.get_a() << "\tB:" << other.get_b() << std::endl;
}
