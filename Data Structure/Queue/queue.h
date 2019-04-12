#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Queue
{
	int Capability;
	int Length;
	int Head;
	int Tail;
	T *que;
public:
	Queue(int capability);
	void Clear();
	bool InQueue(T element);
	bool OutQueue();
	void Print();
	~Queue();
};
template <typename T>
Queue<T>::Queue(int capability) :Capability(capability)
{
	que = new T[Capability];
	Clear();
}
template <typename T>
void Queue<T>::Clear()
{
	Head = Tail = 0;
}
template <typename T>
bool Queue<T>::InQueue(T element)
{
	if (Length == Capability)
		return false;
	else {
		que[Tail++] = element;
		Tail %= Capability;
		Length++;
		return true;
	}
}
template <typename T>
bool Queue<T>::OutQueue()
{
	if (Length != 0)
	{
		Head++;
		Head %= Capability;
		Length--;
		return true;
	}
	else return false;
}
template <typename T>
void Queue<T>::Print()
{
	for (int i = Head; i < Head + Length; i++)
	{
		cout << que[i % Capability] << endl;
	}
}
template <typename T>
Queue<T>::~Queue()
{
	delete[]que;
	que = NULL;
}