#include<iostream>

#define delimiter "\n----------------------------------------\n"
//static . -> (:: - Scope operator)
class Element
{
	int Data;		//�������� ��������
	Element* pNext;	//����� ���������� ��������
	static int count;
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		count++;
		std::cout << "EConstructor:\t" << this << std::endl;
	}
	~Element()
	{
		count--;
		std::cout << "EDestructor:\t" << this << std::endl;
	}
	friend class ForwardList;
};

int Element::count = 0;

class ForwardList
{
	Element* Head;
	unsigned int Size;
public:
	ForwardList()
	{
		Head = nullptr;	//���� ������ ����, �� ��� ������ ��������� �� 0;
		Size = 0;
		std::cout << "LConstructor:\t" << this << std::endl;
	}
	~ForwardList()
	{
		std::cout << "LDestructor:\t" << this << std::endl;
	}

	//			Adding elements:
	void push_front(int Data)
	{
		Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;
		Size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}
		Element* Temp = Head;
		while (Temp->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = new Element(Data);
		Size++;
	}

	void insert(int Index, int Data)
	{
		if (Index > Size)
		{
			std::cout << "Error: Out of range" << std::endl;
			return;
		}
		if (Index == 0)
		{
			push_front(Data);
			return;
		}
		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++)
		{
			Temp = Temp->pNext;
		}
		Element* New = new Element(Data);
		New->pNext = Temp->pNext;
		Temp->pNext = New;
		Size++;
	}

	//			Removing elements:
	void pop_front()
	{
		Element* buffer = Head;	//���������� ����� ���������� ��������
		Head = Head->pNext;	//��������� ������� �� ������
		delete buffer;
		Size--;
	}
	void pop_back()
	{
		Element* Temp = Head;
		while (Temp->pNext->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		delete Temp->pNext;
		Temp->pNext = nullptr;
		Size--;
	}

	//			Methods:
	void print()const
	{
		Element* Temp = Head;		//�������� - ��� ���������, ��� ������ �������� ����� �������� ������ 
									//� ��������� ��������� ������.
		while (Temp != nullptr)
		{
			std::cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << std::endl;
			Temp = Temp->pNext;	//������� �� ��������� �������
		}
		std::cout << "List size: " << Size << " elements.\n";
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n;
	std::cout << "Input list size: "; std::cin >> n;
	//Element e(5);
	ForwardList fl;

	for (int i = 0; i < n; i++)
	{
		fl.push_back(rand() % 200);
	}
	fl.push_back(1024);
	fl.print();
	std::cout << delimiter << std::endl;
	/*fl.pop_front();
	fl.pop_back();
	fl.print();*/

	ForwardList fl2;
	fl2.push_back(3);
	fl2.push_back(5);
	fl2.push_back(8);
	fl2.push_back(13);
	fl2.push_back(21);
	fl2.print();

	int index;
	int value;
	std::cout << "Input index: "; std::cin >> index;
	std::cout << "Input value: "; std::cin >> value;
	fl.insert(index, value);
	fl.print();

	

	/*int* pa = new int(2);
	delete[] pa;

	int* arr = new int[5] {3, 5, 8, 13, 21};
	delete arr;*/
}