#include "node.h"

template <class Type>
Node<Type>::Node() {

}

template <class Type>
Node<Type>::Node(Type x) {
	data = x;
}

template <class Type>
Node<Type>::~Node() {
	weights.erase();
	edge.erase();
}

template <class Type>
void Node<Type>::setdata(Type x) {
	data = x;
}

template <class Type>
vector <float> Node<Type>::getweight() {
	return weights;
}

template <class Type>
void Node<Type>::setweight(vector<float> w) {
	weights = w;
}

template <class Type>
void Node<Type>::setedge(vector<Node<Type>*> ed) {
	edge = ed;
}

template <class Type>
vector <Node<Type>*> Node<Type>::getedge() {
	return edge;
}

int main() {}
