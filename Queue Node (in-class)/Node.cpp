#include "Node.h"

template <class T>
Node<T>::Node() {
	next = NULL;
}

template <class T>
Node<T>::Node(T v) {
	data = v;
	next = NULL;
}

template <class T>
Node<T>::~Node()
{

}

template <class T>
T Node<T>::getdata()
{
	return data;
}

template <class T>
Node <T>*Node<T>::getnext()
{
	return next;
}

template <class T>
void Node<T>::setdata(T v)
{
	data = v;
}

template <class T>
void Node<T>::setnext(Node <T> *n)
{
	next = n;
}
