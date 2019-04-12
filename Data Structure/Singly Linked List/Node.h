#pragma once
template<typename T>
class Node
{
public:
	T date;
	Node *next;
	Node();
	~Node();
};

template<typename T>
inline Node<T>::Node()
{
	next = NULL;
}

template<typename T>
inline Node<T>::~Node()
{
	delete next;
	next = NULL;
}
