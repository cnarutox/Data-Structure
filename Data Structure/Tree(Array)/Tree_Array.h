#pragma once
class Tree_Array
{
	int *tree;
	int Size;
public:
	Tree_Array(int size, int root);
	int* operator[](int index);
	bool Add(int location, int direction, int value);
	bool Delete(int location);
	void Traverse();
	~Tree_Array();
};

