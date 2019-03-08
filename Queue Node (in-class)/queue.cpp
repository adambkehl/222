#include "queue.h"

template <class T>
queue<T>::queue()
{
	first = last = NULL;
}

template <class T>
queue<T>::queue(T v)
{
	first = new Node<T>(v);
	first->setnext(NULL);
	//(*first).setnext(NULL);
	last = first;
}

template <class T>
int queue<T>::length() const
{
	int s = 0;
	Node<T> *temp;
	temp = first;
	while (temp != NULL)
	{
		s++;
		temp = temp->getnext();
	}
	return s;
}

template <class T>
void queue<T>::display() const
{
	Node<T> *temp;
	temp = first;
	while (temp != NULL)
	{
		cout << temp->getdata() << " ";
		temp = temp->getnext();
	}
	cout << endl;
	//return (s);
}

template <class T>
void queue<T>::enqueue(T v)
{
	Node <T> newNode = new Node<T>(v);
	newNode->setNext(first);
	first = newNode;
}

template <class T>
T queue<T>::dequeue() {
	T temp;
	if (first == last) {
		temp = first->getdata();
		delete first;
		first = last = NULL;
		return temp;
	}
	temp = last->getdata();
	Node <T> *t;
	t = first;
	while (t->getnext() != last) t = t->getnext();
	t->setnext(NULL);
	delete last;
	last = t;
	return temp;
}
