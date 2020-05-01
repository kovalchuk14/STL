#include <iostream>
#include <string>

class Binary
{
	int Data;
	int* bin;
	int size;
public:
	const int get_Data()const
	{
		return Data;
	}
	int get_Data()
	{
		return Data;
	}
	int capacity(int decimal)
	{
		int i = 0;
		for (; decimal; i++, decimal /= 2);
		return i;
	}
	
	void print()
	{
		for (int i = 0; i < capacity(Data); i++)
		{
			std::cout << this->bin[i] << "\t";
		}
		std::cout << std::endl;
	}
	Binary(int Data) :Data(Data)
	{
		int mod;
		size = capacity(Data);
		bin = new int[size];
		for (int i = size; i; i--)
		{
			mod = Data % 2;
			Data /= 2;
			bin[i-1] = mod;
		}
		std::cout << "Constructor:\t" <<this<< std::endl;
	}
	~Binary()
	{
		std::cout << "Destructor:\t" <<this<< std::endl;
	}
	bool operator==(Binary other)
	{
		return this->Data == other.Data;
	}
	bool operator!=(Binary other)
	{
		return !(this->Data == other.Data);
	}
	int* operator !()
	{
		for (int i = 0; i <	capacity(Data); i++)
		{
			if (bin[i])bin[i] = 0;
			else bin[i] = 1;
		}
		return bin;
	}
	int* operator |(Binary other)
	{
		for (int i = 0; (i < this->size && i < other.size); i++)
		{
			if (!this->bin[i] && !other.bin[i])this->bin[i]=0;
			else this->bin[i] = 1;
		}
		return this->bin;
	}
	int* operator &(Binary other)
	{
		for (int i = 0; (i < this->size&& i < other.size); i++)
		{
			if (this->bin[i] && other.bin[i])this->bin[i] = 1;
			else this->bin[i] = 0;  
		}

		return this->bin;
	}
	
	
};
std::ostream& operator<<(std::ostream& os, const Binary& b)
{
	os << b.get_Data();
	return os;
}

void main()
{
	setlocale(LC_ALL, " ");
	Binary i = 100;
	Binary a = 105;
	//a.print();
	//i|a;
	//i&a;
	//!i
	//Binary(10).print();
	//i.print();
}