#include<iostream>

//��������� - ��� ��� ������.
//����� - ��� ��� ������.

class Point
{
	double x;
	double y;
public:
	double get_x() const
	{
		return x;
	}
	double get_y() const
	{
		return y;
	}
	void set_x(double x)
	{
		if (/*x >= -100 && x <= 100*/ abs(x)<=100)
		{
			this->x = x;
		}
		else
		{
			this->x = 0;
		}
		//if ��������������� ������������ ��������
	}
	void set_y(double y)
	{
		this->y = y;
	}
};

//#define BASICS
#define ENCAPSULATION

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASICS
	int a;	//���������� ���������� 'a', ���� 'int'.
	Point A;//���������� ���������� 'A', ���� 'Point'.
			//�������� (����������) ������� 'A' ���� 'Point'.
	A.x = 5;
	A.y = 2;
	std::cout << A.x << "\t" << A.y << std::endl;

	Point* pA = &A;
	std::cout << pA->x << "\t" << pA->y << std::endl;
	std::cout << (*pA).x << "\t" << (*pA).y << std::endl;

	/*

	. - �������� ������� ������� (Point operator),
		������������ ��� ��������� � ����� (������) ������� �� ����� �������.
	-> - �������� ���������� ������� (Arrow operator),
		������������ ��� ��������� � ����� �������, �� ������ �������.
		����� ��������� ��������, ����� ��� ������ ����� ����������,
		�� �� ������ ����� ������ ����� ������� ��� ������ 'this'.

	*/
#endif // BASICS

#ifdef ENCAPSULATION
	Point A;
	A.set_x(5);
	A.set_y(3);
	std::cout << A.get_x() << "\t" << A.get_y() << std::endl;
#endif // ENCAPSULATION

}