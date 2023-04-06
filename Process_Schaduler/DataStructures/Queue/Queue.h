#pragma once
#include "../Node.h"

#include<iostream>
#define null NULL
using namespace std;
template <class type>
class Queue {
	Node<type>* front = null;
	Node<type>* rear = null;
public:
	int count = 0;
	void enQueue(type val) {
		if (rear == null) {
			rear = front = new Node<type>(val, null);
			count++;
			return;
		}
		rear->next = new Node<type>(val, null);
		rear = rear->next;
		count++;
	}
	bool isEmpty() {
		return count == 0;
	}
	type top() {
		return front->val;
	}
	void dequeue() {
		if (front != null) {
			type d = front->val;
			Node<type>* n = front->next;
			delete front;
			front = n;
			count--;
		}
	}
};