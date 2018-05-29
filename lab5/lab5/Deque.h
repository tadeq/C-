#ifndef DEQUE_H
#define DEQUE_H

#include "Empty_queue_exception.h"
#include "Node.h"
#include <iostream>

template<typename T>
class Deque
{
	Node<T>* head;
	Node<T>* tail;
public:
	Deque() : head(NULL), tail(NULL) {};
	Deque(const Deque &) = delete;
	~Deque();
	Node<T>* get_head();
	Deque operator=(const Deque &) = delete;
	bool put(T val);
	bool get();
	template<typename U>
	friend std::ostream & operator<<(std::ostream &, Deque<T> &);
};

template<typename T>
Deque<T>::~Deque()
{
	delete head;
	delete tail;
}

template<typename T>
Node<T>* Deque<T>::get_head()
{
	return head;
}

template<typename T>
bool Deque<T>::put(T val)
{
	Node<T>* node = new Node<T>(val);
	node->set_next(head);
	head = node;
	return true;
}

template<typename T>
bool Deque<T>::get()
{
	if (head == NULL) {
		throw Empty_queue_exception();
	}
	Node<T>* node = head;
	head = head->next;
	delete node;
	return true;
}

template<typename T>
std::ostream & operator<<(std::ostream & os, Deque<T>& deque)
{
	os << "[";
	Node<T>* tmp = deque.get_head();
	while (tmp != NULL) {
		os << tmp->get_value() << ", ";
		tmp = tmp->get_next();
	}
	os << "]";
	return os;
}

#endif