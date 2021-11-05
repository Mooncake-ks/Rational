#include <iostream>
#include <string>
#pragma once
class Rational
{
public:
	//�� ���������
	Rational();
	//� �����������
	Rational(int a, int b = 1);
	//����������� �����������
	Rational(Rational* other);

	//����� ���������� ����
	int ToInt();
	//������������
	double ToDouble();

	//�������������� �����
	Rational* Inverse();
	std::string ToStr();

	//�������� � ����������
	void operator =(const Rational* other);
	Rational* operator +(const Rational& other);
	Rational* operator -(const Rational& other);
	Rational* operator *(const Rational& other);
	Rational* operator /(const Rational& other);

	Rational* operator +(const int& a);
	Rational* operator -(const int& a);
	Rational* operator /(const int& a);
	//������ � ������
	int get_a();
	int get_b();
private:
	int m_a;
	int m_b;
};
