#include "Tree_Array.h"
#include <iostream>
#define left -1
#define right 1
using namespace std;
Tree_Array::Tree_Array(int size, int root):Size(size)
{
	tree = new int[size];
	for (int i = 0; i < size; i++)
	{
		if (i == 0) tree[i] = root;
		else tree[i] = 0;
	}
}

int* Tree_Array::operator[](int index)
{
	if (index >= 0 && index < Size && tree[index] != 0)
		return tree+index;
	else return nullptr;
}

bool Tree_Array::Add(int location, int direction, int value)
{
	if (location >= 0 && location < Size)
		switch (direction)
		{
		case left:if (location * 2 + 1 < Size)
		{
			tree[location * 2 + 1] = value; return true;
		}
				  else break;
		case right:if (location * 2 + 2 < Size)
		{
			tree[location * 2 + 2] = value; return true;
		}
				   else break;
		}
	return false;
}

bool Tree_Array::Delete(int location)
{
	if (location >= 0 && location < Size)
	{
		tree[location] = 0;
		return true;
	}
	else return false;
}

void Tree_Array::Traverse()
{
	for (int i = 0; i < Size; i++)
		if(tree[i] != 0)
			cout << tree[i] << endl;
}

Tree_Array::~Tree_Array()
{
	delete[]tree;
	tree = nullptr;
}
