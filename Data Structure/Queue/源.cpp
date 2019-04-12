#include "queue.h"
#include <iostream>
using namespace std;
int main()
{
	Queue<int> q(3);
 	q.InQueue(1);
 	q.InQueue(2);
 	q.InQueue(3);
	q.Print();
		return 0;
}