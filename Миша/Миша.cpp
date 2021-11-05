#include <iostream>
#include <utility>
#include "Rational.h"

void print(Rational& other);

int main()
{
	//Creat
	Rational r1 = new Rational{}; //0/1
	Rational r2 = new Rational{ 5,3 }; //5/1
	Rational r3 = new Rational{ -3,4 }; //-3/4

	//converting back
	int a = r1.ToInt();			//0
	double b = r2.ToDouble();	//5.0
	//a/b => b/a
	std::cout << (r2.Inverse())->ToStr() << "\n";			// 0/1 => 1/5
	std::cout << (r2 + r3)->ToStr() << "\n";				// 5/1 + 3/4 => 23/4
	std::cout << (r2 - r3)->ToStr() << "\n";				// 5/1 - 3/4 => 17/4
	std::cout << (r2 * r3)->ToStr() << "\n";				// 5/1 * 3/4 => 15/4
	std::cout << (r2 / r3)->ToStr() << "\n";				// 5/1 : 3/4 => 20/3
	std::cout << (r2 + 1)->ToStr() << "\n";				// 5/1 + 1 => 6/1
	std::cout << (r2 - 1)->ToStr() << "\n";					// 5/1 - 1 => 4/1
	std::cout << (r2 * 3)->ToStr() << "\n";					// 5/1 * 3 => 15/1
	std::cout << (r2 / 3)->ToStr() << "\n";				// 5/1 : 3 => 5/3

	return 0;
}

//Старый метод
void print(Rational& other)
{
	std::cout << "Point : \n A:" << other.get_a() << "\tB:" << other.get_b() << std::endl;
}