#pragma once
#include <iostream>
using namespace std;

template <typename T>
class List
{
	T *list;
	int Size;
	int length;
public:
	List(int size);
	void Clear();
	int Length();
	T operator[](int index);
	int Locate(T element);
	T Prior(T element);
	T Next(T element);
	bool Insert(T element, int locate);
	bool Insert(T element);
	bool Delete(int location);
	void Traverse();
	~List();
};

template<typename T>
List<T>::List(int size):Size(size)
{
	list = new T[size];
	Clear();
}

template<typename T>
inline void List<T>::Clear()
{
	length = 0;
}

template<typename T>
int List<T>::Length()
{
	return this->length;
}

template<typename T>
T List<T>::operator[](int index)
{
	if (index >= 0 && index < length)
		return list[index];
	else throw string("Out Of Border");
}

template<typename T>
int List<T>::Locate(T element)
{
	for (int i = 0; i < length; i++)
	{
		if (element == list[i])
			return i;
	}
	return Size;
}

template<typename T>
T List<T>::Prior(T element)
{
	int i = Locate(element);
	if (i != Size && i != 0)
		return list[i - 1];
	else throw string("Not Found");
}

template<typename T>
T List<T>::Next(T element)
{
	int i = Locate(element);
	if (i != Size && i != length)
		return list[i + 1];
	else throw string("Not Found");
}

template<typename T>
inline bool List<T>::Insert(T element, int location)
{
	if (location >= 0 && location <= length && length < Size)
	{
		for (int i = length - 1; i >= locate; i--)
			list[i + 1] = list[i];
		list[location] = element;
		length++;
		return true;
	}
	else throw string("Fail To Insert");
}

template<typename T>
inline bool List<T>::Insert(T element)
{
	if (length < Size)
	{
		list[length] = element;
		length++;
		return true;
		
	}
	else throw string("Fail To Insert");
}

template<typename T>
inline bool List<T>::Delete(int location)
{
	if (location >= 0 && location < length && length > 0)
	{
		for (int i = location; i < length - 1; i++)
			list[i] = list[i + 1];
		length--;
		return true;
	}
	else throw string("Fail To Delete");
}

template<typename T>
inline void List<T>::Traverse()
{
	for (int i = 0; i < length; i++)
		cout << list[i] << endl;
}

template<typename T>
inline List<T>::~List()
{
	delete[]list;
	list = nullptr;
}
