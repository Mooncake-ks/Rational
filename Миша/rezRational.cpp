#include <iostream>
#include <utility>
#include <string>
#include "Rational.h"

//Конструкторы
Rational::Rational() :m_a{ 0 }, m_b{ 1 } {}
Rational::Rational(int a, int b) : m_a{ a }, m_b{ b }{}
Rational::Rational(Rational* other) : m_a{ other->m_a }, m_b{ other->m_b }{}

//методы
int Rational::ToInt()
{
	return m_a / m_b;
}

double Rational::ToDouble()
{
	return static_cast<double>(m_a) / static_cast<double>(m_b);
}

Rational* Rational::Inverse()
{
	return new Rational{ this->m_b,this->m_a };
}

std::string Rational::ToStr()
{
	//Для корректной работы нужно привести к нормальной форме
	if (m_a == 0)
	{
		return "0";
	}
	else if (m_b == 1)
	{
		return std::to_string(m_a);
	}
	else
	{
		return std::to_string(m_a) + "/" + std::to_string(m_b);
	}
}
//операции с объектами класса
void Rational::operator=(const Rational* other)
{
	this->m_a = other->m_a;
	this->m_b = other->m_b;
}

Rational* Rational::operator+(const Rational& other)
{
	if (this->m_b % other.m_b == 0 || other.m_b % this->m_b == 0)
	{
		int x = this->m_b > other.m_b ? this->m_b : other.m_b;
		return new Rational(((x / this->m_b) * this->m_a) + ((x / other.m_b) * other.m_a), x);
	}
	int y = this->m_b * other.m_b;
	return new Rational(((y / this->m_b) * this->m_a) + ((y / other.m_b) * other.m_a), y);
}

Rational* Rational::operator-(const Rational& other)
{
	if (this->m_b % other.m_b == 0 || other.m_b % this->m_b == 0)
	{
		int x = this->m_b > other.m_b ? this->m_b : other.m_b;
		return new Rational(((x / this->m_b) * this->m_a) - ((x / other.m_b) * other.m_a), x);
	}
	int y = this->m_b * other.m_b;
	return new Rational(((y / this->m_b) * this->m_a) - ((y / other.m_b) * other.m_a), y);
}

Rational* Rational::operator*(const Rational& other)
{
	return  new Rational{ this->m_a * other.m_a, this->m_b * other.m_b };
}

Rational* Rational::operator/(const Rational& other)
{
	return  new Rational{ this->m_a * other.m_b, this->m_b * other.m_a };
}

//операции со значениями
Rational* Rational::operator+(const int& a)
{
	return new Rational{ (a * this->m_b) + this->m_a,this->m_b };
}

Rational* Rational::operator-(const int& a)
{
	return new Rational{ this->m_a - (a * this->m_b),this->m_b };
}

Rational* Rational::operator/(const int& a)
{
	return new Rational(Rational{ this->m_a,this->m_b } / Rational{ a });
}

//доступ к полям
int Rational::get_a()
{
	return m_a;
}

int Rational::get_b()
{
	return m_b;
}