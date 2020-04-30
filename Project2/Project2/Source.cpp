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
		return decimal;
	}
	
	int& init_bin(int Data)//вот мне нужна длинна для того что бы из 10 сделать 2
	{
		int mod;
		size = capacity(Data);
		bin = new int[size];
		int i = 0;
		while (Data)
		{
			mod = Data % 2;
			Data /= 2;

			bin[i] = mod;
		}
		
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
		std::cout << "Constructor:\t" << std::endl;
	}
	~Binary()
	{
		std::cout << "Destructor:\t" << std::endl;
	}
	bool operator==(Binary other)
	{
		return this->Data == other.Data;
	}
	bool operator!=(Binary other)
	{
		return !(this->Data == other.Data);
	}
	Binary operator !()
	{
		for (int i = 0; i <	capacity(Data); i++)
		{
			if (bin[i])bin[i] = 0;
			else bin[i] = 1;
		}//ну тут легко меняю значение на противоположное 
	
	}
	Binary operator |(Binary other)
	{
		for (int i = 0; (i < this->capacity(Data) && i < other.capacity(Data)); i++)
		{
			if (!this->bin[i] && !other.bin[i])this->bin[i]=0;
			else this->bin[i] = 1;
		}
		
	}
	Binary operator &(Binary other)
	{
		for (int i = 0; (i < this->capacity(Data) && i < other.capacity(Data)); i++)
		{
			if (this->bin[i] && other.bin[i])this->bin[i] = 1;
			else this->bin[i] = 0;  
			

		}
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
	i.init_bin();
	i.print();

}