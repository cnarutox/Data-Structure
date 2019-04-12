#pragma once
#include <iostream>
using namespace std;

template<typename T>
class node 
{
public:
	T date;
	node *next;
	node(T element);
	node() { next = nullptr; };
	void PrintNode();
	friend std::ostream & operator<<(std::ostream &out, node<T> element);
	~node();	
};

template<typename T>
inline node<T>::node(T element) :date(element)
{
	next = nullptr;
}

template<typename T>
inline void node<T>::PrintNode()
{
	//cout << data << endl;
}

template<typename T>
inline node<T>::~node()
{
}

template<typename T>
std::ostream & operator<<(std::ostream &out, node<T> element)
{
	out << element.date;
	return out;
}