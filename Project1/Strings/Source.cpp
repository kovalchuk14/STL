#include <iostream>
using namespace std;

void main()
{
	wchar_t str[] = L"Hello";
	wcout << str << endl;
	wcout << wcslen(str) << endl;

}