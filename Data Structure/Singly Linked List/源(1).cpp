#include "list.h"

int main()
{
	try
	{
		list<int> l;
		node<int> a(3);
		l.InsertTail(1);
		l.InsertTail(2);
		l.InsertTail(a);
		l.InsertHead(-1);
		l.Insert(4, 5);
		l.Insert(5, 6);
		l.Delete(6);
		l.Insert(l.Prior(4), 6);
		l.Print();
		cout << a;
	}
	catch (std::string &a)
	{
		cout << a; 
	}
	return 0;
}