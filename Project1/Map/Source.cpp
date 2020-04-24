#include <iostream>
#include<string>
#include<map>
#include<list>
#include<vector>

//#define STL_MAP
#define DICTIONARY

void main()
{
	setlocale(LC_ALL, " ");
#ifdef STL_MAP
	std::map<int, std::string>week =
	{
		std::pair<int,std::string>(0,"Sunday"),
		std::pair<int,std::string>(1,"Monday"),
		std::pair<int,std::string>(2,"Tuesday"),
		std::pair<int,std::string>(3,"Wednesday"),
		std::pair<int,std::string>(4,"Thursday"),
		std::pair<int,std::string>(5,"Friday"),
		std::pair<int,std::string>(6,"Saturday"),
	};

	int number;
	std::cout << "1 to 7: "; std::cin >> number;
	/*for (std::map<int, std::string>::iterator it = week.begin(); it != week.end(); it++)
	{
		std::cout<<it->first << "\t" << it->second << std::endl;

	}*/
	std::cout << "Day of the week " << week.find(number )->second << std::endl;
#endif
#ifdef DICTIONARY

	std::map<std::string, std::vector<std::string>>dictionary =
	{
		std::pair<std::string,std::vector<std::string>>("friend",{"друг","приятель" }),
		std::pair<std::string,std::vector<std::string>>("space",{ "космос","пробел" }),
		std::pair<std::string,std::vector<std::string>>("flour",{ "мука"}),
	};
	for (std::map<std::string, std::vector<std::string>>::iterator it = dictionary.begin(); it != dictionary.end(); it++)
	{
		std::cout << (*it).first << "\t";
		for (std::vector<std::string>::iterator jt = it->second.begin(); jt != it->second.end(); jt++)
		{
			std::cout << *jt << ", ";
		}
		std::cout << "\b\b;\n";
	}


#endif

}