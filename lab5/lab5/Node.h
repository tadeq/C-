#ifndef NODE_H
#define NODE_H

#include <iostream>

template<typename T> class Deque;

template <typename T>
class Node
{
	T value;
	Node<T>* next;
	Node<T>* prev;
public:
	Node(T val) : value(val) {};
	~Node();
	T get_value();
	Node <T>* get_next();
	void set_next(Node<T>*);
	void print() const;
};

template <typename T>
Node<T>::~Node() {
	delete next;
	delete prev;
}

template<typename T>
T Node<T>::get_value()
{
	return value;
}

template<typename T>
Node<T>* Node<T>::get_next()
{
	return next;
}

template<typename T>
void Node<T>::set_next(Node<T>* node)
{
	next = node;
}

template<typename T>
void Node<T>::print() const
{
	std::cout << value;
	if (this->next != NULL) next->print();
}

#endif