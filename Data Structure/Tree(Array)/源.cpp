#include "Tree_Array.h"
#include <iostream>
using namespace std;
#define left -1
#define right 1
int main()
{
	Tree_Array a(10, 1);
	a.Add(0, left, 2);
	a.Add(0, right, 3);
	a.Add(1, left, 4);
	a.Delete(3);
	cout << *a[0] << endl;
	a.Traverse();
	return 0;
}