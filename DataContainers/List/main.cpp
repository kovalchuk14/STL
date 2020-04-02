#include "Header.h "
#include <iostream>
#include <string>

//#define BASE_CHECK

void main()
{
	int n;
	//std::cout << "Input list size: "; std::cin >> n;
#ifdef BASE_CHECK
	List list;
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}
	list.print();
	list.print_revers();
	//std::cout << "____________________________add front___________________________________" << std::endl;
	//list.push_front(100);
	//list.print();
	//list.print_revers();
	//std::cout << "____________________________add back____________________________________" << std::endl;
	//list.push_back(200);
	//list.print();
	//list.print_revers();
	//std::cout << "__________________________delete front__________________________________" << std::endl;
	//list.pop_front();
	//list.print();
	//list.print_revers();
	//std::cout << "__________________________delete back___________________________________" << std::endl;
	//list.pop_back();
	//list.print();
	//list.print_revers();
	std::cout << "______________________________insert____________________________________" << std::endl;
	int index;
	int data;
	try
	{
		std::cout << "Input index: "; std::cin >> index;
		//	std::cout << "Intex value: "; std::cin >> data;
		list.erase(index);
		list.print();
		list.print_revers();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	/*List list = { 3,5,8 };
	list.print();
	list.print_revers();
	List list2 = list;
	list2.print();
	list2.print_revers();
	int arr[] = { 3,5,8,13,21 };
	for (int i : arr)
	{
		std::cout << i << "\t";
	}*/
	List list = { 3,5,8,13,21 };

	for (List::Iterator it = list.begin(); it != list.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;

	for (int i : list)
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;
	List list2 = { 34,55,89 };

	for (List::Iterator it = list2.begin(); it != list2.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;
	/*for (int i : list + list2)
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;
	*/
	List list3;
	list3 = list + list2;
	list3.print();
#endif // BASE_CHECK
	/*List<double> list1 = { 3.7,5,8,13,21 };
	for (List<double>::Iterator it = list1.begin(); it != list1.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;
	List<double> list2 = { 34,55,89 };
	for (double i : list2)std::cout << i << "\t";
	std::cout << std::endl;
	List<double>list3 = list1 + list2;
	list3.print();*/
	/*List<double> list2 = { 2.4, 3.14, 5.5 };
	for (double i : list2)std::cout << i << "\t";
	List<std::string> list3 = { "Hello","World","How","Are","You" };
	for(std::string i:list3)
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;*/
	List<std::string> list1 = { "Hello","World"};
	for (List<std::string>::Iterator it = list1.begin(); it != list1.end(); it++)
	std::cout << *it << "\t";
	std::cout << std::endl;
	List<std::string> list2 = {"Hello","You" };
	for (std::string i : list2)std::cout << i << "\t";
	std::cout << std::endl;
	List<std::string>list3 = list1 + list2;
	list3.print();
}