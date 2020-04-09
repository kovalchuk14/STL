#include <iostream>

class BTree
{
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr) :Data(Data), pLeft(pLeft), pRight(pRight)
		{
			std::cout << "EConstructor:\t" << this << std::endl;
		}
		~Element()
		{
			std::cout << "EDestructor:\t" << this << std::endl;
		}
		friend class BTree;
	}*Root;
public:
	Element* getRoot()
	{
		return this->Root;
	}
	BTree() :Root(nullptr)
	{
		std::cout << "TConstructor:\t" << this << std::endl;
	}
	BTree(const std::initializer_list<int>&il) :BTree()
	{
		for (int i : il)
		{
			insert(i);
		}
	}
	BTree(const BTree& other) :BTree()
	{
		copy(this->Root, other.Root);
		std::cout << "BTCopyConstructor:\t" << this << std::endl;
	}
	~BTree()
	{
		clear(this->Root);
		this->Root = nullptr;
		std::cout << "TDestructor:\t" << this << std::endl;

	}
	BTree& operator=(const BTree& other)
	{
		if (this == &other)return *this;
		clear();
		copy(this->Root, other.Root);
		std::cout << "BTCopyAssignement:\t" << this << std::endl;
		return *this;
	}
	void copy(Element* ThisRoot, Element* OtherRoot)
	{
		if (!OtherRoot)return;
		ThisRoot = new Element(OtherRoot->Data);
		copy(ThisRoot->pLeft, OtherRoot->pLeft);
		copy(ThisRoot->pRight, OtherRoot->pRight);
	}
	//adding elements

	void insert(int Data,Element* Root)
	{
		if (this->Root == nullptr)
		{
			this->Root = new Element(Data);
			return;
		}
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else if(Data>Root->Data)
		{
			if (Root->pRight== nullptr)Root->pRight= new Element(Data);
			else insert(Data, Root->pRight);
		}
	}
	void erase(int Data, Element*& Root)
	{
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			erase(Data, Root->pLeft);

		}
		else if (Data> Root->Data)
		{
			erase(Data, Root->pRight);
		}
		else // (Data == Root->Data)
		{
			if (Root->pLeft == Root->pRight)
			{
				delete Root;
				Root = nullptr;
			}
			else if (count(Root->pLeft)>count(Root->pRight))
			{
				Root->Data = max(Root->pLeft);
				erase(max(Root->pLeft), Root->pLeft);
			}
			else
			{
				Root->Data = min(Root->pRight);
				erase(min(Root->pRight), Root->pRight);
			}
		}

	}

	//Wrapers
	void erase(int Data)
	{
		erase(Data, this->Root);
	}	
	void insert(int Data)
	{
		insert(Data, this->Root);
	}
	void clear()
	{
		clear(this->Root);
		this->Root = nullptr;
	}
	int min()const
	{
		return min(this->Root);
	}
	int max()const
	{
		return max(this->Root);
	}
	double avg()const
	{
		return (double)sum(this->Root) / count(this->Root);
	}
	int sum()const
	{
		return sum(this->Root);
	}
	int count()const
	{
		return count(this->Root);
	}
	void print()
	{
		print(this->Root);
		std::cout << std::endl;
	}

	//methods

	void clear(Element* Root)
	{
		if (!Root)return;
		clear(Root->pLeft);
		clear(Root->pRight);
		delete Root;
	}
	int min(Element* Root)const
	{
		if (Root->pLeft)
		{
			min(Root->pLeft);
		}
		else
		{
			return Root->Data;
		}
	}
	int max(Element* Root)const
	{
		if (Root->pRight)
		{
			max(Root->pRight);
		}
		else
		{
			return Root->Data;
		}
	} 

	int sum(Element* Root)const
	{
		if (!Root)return 0;
		return sum(Root->pLeft) + sum(Root->pRight)+Root->Data;
	}

	int count(Element* Root)const
	{
		if (!Root)return 0;
		return count(Root->pLeft) + count(Root->pRight) + 1;
	}
	
	void print(Element* Root)const
	{
		if (Root == nullptr)return;
		print(Root -> pLeft);
		std::cout << Root->Data << "\t";
		print(Root->pRight);
	}
};
//#define BASE_CHECK
void main()
{
	setlocale(LC_ALL," ");
#ifdef BASE_CHECK
	T800.print(T800.getRoot());
	std::cout << std::endl;	
	std::cout << "min value: " << T800.min() << std::endl;
	std::cout << "max value: " << T800.max() << std::endl;
	std::cout << "size: " << T800.count() << std::endl;
	std::cout << "sum: " << T800.sum() << std::endl;
	std::cout << "Average: " << T800.avg() << std::endl;
#endif
	int n;
	//std::cout << "Input number of Element: "; std::cin >> n;
	BTree T800 = {50,25,30,75,64,85};
	T800.print();

    /*int value;
    std::cout << "Type value to erase: "; std::cin >> value;
    T800.erase(value);
    T800.print();*/
	BTree T1000;
	T1000 = T800;
	T1000.print();
}