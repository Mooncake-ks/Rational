#include <iostream>
#include <string>
#pragma once
class Rational
{
public:
	//По умолчанию
	Rational();
	//С параметрами
	Rational(int a, int b = 1);
	//конструктор копирования
	Rational(Rational* other);

	//Целое округление вниз
	int ToInt();
	//Апроксимация
	double ToDouble();

	//переварачивает дробь
	Rational* Inverse();
	std::string ToStr();

	//Операции и перегрузка
	void operator =(const Rational* other);
	Rational* operator +(const Rational& other);
	Rational* operator -(const Rational& other);
	Rational* operator *(const Rational& other);
	Rational* operator /(const Rational& other);

	Rational* operator +(const int& a);
	Rational* operator -(const int& a);
	Rational* operator /(const int& a);
	//Доступ к данным
	int get_a();
	int get_b();
private:
	int m_a;
	int m_b;
};
