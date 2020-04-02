#pragma once
#include <iostream>
#include <string>

template <typename T>
class List
{
	class Element
	{
		T data;
		Element*pNext;
		Element*pPrev;
	public:
		Element(T data, Element*pNext, Element*pPrev = nullptr) :data(data), pNext(pNext), pPrev(pPrev);
		~Element();
		friend class List;
	};
	Element*head;//Содержет указатель на начало списка
	Element*tail;//Содержет указатель на конец списка
	unsigned int size;//количество элементов списка
public:
	class Iterator
	{
		Element* Temp;
	public:
		Iterator(Element* Temp);
		~Iterator();
		//Operator
		Iterator& operator++();
		Iterator& operator++(int);
		const T& operator*()const;
		T& operator*();
		bool operator==(const Iterator& other)const;
		bool operator!=(const Iterator& other)const;

	};

	const Iterator begin()const;
	const Iterator end()const;
	Iterator begin();
	Iterator end();

	List();
	List(const std::initializer_list<T>& il);
	List(const List& other);
	List(List&& other);
	~List();
	//Operators
	List& operator=(const List& other);
	List operator=(List&& other);	
	//adding elements
	void push_front(T data);
	void push_back(T data);
	void insert(int index, T data);
	//delete elements
	void pop_front();
	void pop_back();
	void erase(int index);
	//removing elemtnts

	//metods
	void print()const;
	void print_revers()const;
};
template <typename T>
List<T> operator+(const List<T>& left, const List<T>& right);