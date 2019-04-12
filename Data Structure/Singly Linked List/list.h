#pragma once
#include "Node.h"
template<class T>
class list
{
	Node<T> *l;
	int length;
public:
	list();
	void Clear();
	int Length();
	int Locate(Node<T> element);
// 	T Prior(Node element);
// 	T Next(Node element);
// 	bool Insert(T element, int locate);
// 	bool InsertTail(T element);
// 	bool Delete(int location);
// 	void Traverse();
 	~list();
};

template<class T>
inline list<T>::list()
{
	Clear();
}

template<class T>
inline void list<T>::Clear()
{
	length = 0;
	l = NULL;
}

template<class T>
inline int list<T>::Length()
{
	return length;
}

template<class T>
inline int list<T>::Locate(Node<T> element)
{
	for (Node *i = l, int j = 0; i->next != NULL; i = i->next, j++)
	{
		if (*i == element)
			return j;
	}
	return 0;
}

template<class T>
inline list<T>::~list()
{
	delete l;
	list = NULL;
}
