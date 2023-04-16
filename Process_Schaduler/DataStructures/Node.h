#pragma once
template <class type>
class Node {
public:
	type val;
	Node<type>* next;
	int weight = 0;
	Node(type v, Node<type>* n,int w = 0) {
		val = v;
		next = n;
		weight = w;
	}
};