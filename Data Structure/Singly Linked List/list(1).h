#pragma once
#include "node.h"
#include <string>
#include <iostream>
using namespace std;
template<class T>
class list
{
	node<T> *l;
	int length;
public:
	list();
	void Clear();
	int Length();
	int Locate(node<T> element);
	node<T> Prior(node<T> element);
	node<T> Next(node<T> element);
	bool Insert(node<T> element, int locate);
	bool InsertHead(node<T> element);
	bool InsertTail(node<T> element);
	void Print();
	bool Delete(int location);
	// 	void Traverse();
	~list();
};

template<class T>
inline list<T>::list()
{
	l = new node<T>;
	Clear();
}

template<class T>
inline void list<T>::Clear()
{
	length = 1;
	for (node<T> *i = l->next; i != nullptr;)
	{
		node<T> *temp = i->next;
		delete i;
		i = temp;
	}
	l->next = nullptr;
	l->date = 0;
}

template<class T>
inline int list<T>::Length()
{
	return length;
}

template<class T>
inline int list<T>::Locate(node<T> element)
{
	for (node *i = l, int j = 0; i->next != nullptr; i = i->next, j++)
	{
		if (i.date == element.date)
			return j;
	}
	throw string("Not Found");
}

template<class T>
inline node<T> list<T>::Prior(node<T> element)
{
	for (node<T> *i = l; i->next != nullptr; i = i->next)
	{
		if (i->next->date == element.date)
			return *i;
	}
	throw string("Not Found");
}

template<class T>
inline node<T> list<T>::Next(node<T> element)
{
	for (node<T> *i = l; i->next != nullptr; i = i->next)
	{
		if (i->date == element.date)
			return *(i->next);
	}
	throw string("Not Found");
}

template<class T>
inline bool list<T>::Insert(node<T> element, int locate)
{
	if (locate == 0)
		InsertHead(element);
	else if (locate == length)
		InsertTail(element);
	else
	{
		int j = 0;
		for (node<T> *i = l; i->next != nullptr && j <= locate; i = i->next, j++)
		{
			if (j == locate - 1)
			{
				node<T> *ele = new node<T>;
				ele->date = element.date;
				ele->next = i->next;
				i->next = ele;
				length++;
				return true;
			}
		}
		throw string("Fail To Insert");
	}
	return true;
}

template<class T>
inline bool list<T>::InsertHead(node<T> element)
{
	node<T> *ele = new node<T>;
	if (ele == nullptr)
		throw string("Fail To Apply For RAM");
	ele->date = element.date;
	ele->next = l;
	l = ele;
	length++;
	return true;
}

template<class T>
inline bool list<T>::InsertTail(node<T> element)
{
	node<T> *i = l;
	node<T> *ele = new node<T>;
	ele->date = element.date;
	for (; i->next != nullptr; i = i->next);
	if (ele == nullptr)
		throw string("Apply For RAM");
	i->next = ele;
	length++;
	return true;
}

template<class T>
inline void list<T>::Print()
{
	for (node<T> *i = l; i != nullptr; i = i->next)
	{
		cout << i->date << endl;
		//i->PrintNode();
	}
}

template<class T>
inline bool list<T>::Delete(int location)
{
	int j = 0;
	if (location == 0 && l->next != nullptr)
	{
		node<T> *temp = l;
		l = l->next;
		delete temp;
		length--;
		return true;
	}
	else
		for (node<T> *i = l; i != nullptr && j <= location; i = i->next, j++)
		{
			if (j == location - 1 && i->next != nullptr)
			{
				node<T> * temp = i->next;
				i->next = i->next->next;
				delete temp;
				length--;
				return true;
			}
		}
	throw string("Fail To Delete");
}

template<class T>
inline list<T>::~list()
{
	Clear();
	delete l;
	l = nullptr;
}