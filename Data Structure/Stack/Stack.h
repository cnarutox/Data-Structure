#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Stack
{
	int Size;
	int Top;
	T *sta;
public:
	Stack(int size);
	bool Push(T element);
	bool Pop();
	T Pop(T &element);
	void Print();
	void Clear();
	~Stack();
};
template <typename T>
Stack<T>::Stack(int size) :Size(size)
{
	Clear();
	sta = new T[size];
}
template <typename T>
bool Stack<T>::Push(T element)
{
	if (Top == Size)
		return false;
	else {
		sta[Top++] = element;
		return true;
	}
}
template <typename T>
bool Stack<T>::Pop()
{
	if (Top == 0)
		return false;
	else {
		Top--;
		return true;
	}
}
template<typename T>
T Stack<T>::Pop(T &element)
{
	if (Top == 0)
		return false;
	else
		return element = sta[--Top];
}
template <typename T>
void Stack<T>::Print()
{
	for (int i = Top - 1; i >= 0 ; i--)
		cout << sta[i] << endl;
}
template<typename T>
inline void Stack<T>::Clear()
{
	Top = 0;
}
template <typename T>
Stack<T>::~Stack()
{
	delete[]sta;
	sta = nullptr;
}


