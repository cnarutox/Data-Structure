#include "List in order.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	List<int> l(3);
	try
	{
		l.Insert(1);
		l.Insert(2);
		l.Insert(3);
		l.Traverse();
		cout << l.Prior(2) << l.Next(2);
	}
	catch (string a)
	{
		cout << a;
	}
	return 0;
}