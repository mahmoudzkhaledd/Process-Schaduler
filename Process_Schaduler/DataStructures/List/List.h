#pragma once
#include "../Node.h"
#define null NULL
#include<iostream>
#include<vector>
using namespace std;
template <typename T>
class List {
	//vector<T> v;
	Node<T>* front = null;
	Node<T>* tail = null;
public:
	int count = 0;
	T LastElement() {
		//return l[l.size()-1];
		//return tail->val;
		return null;
	}
	T elementAt(int index) {
		//return v[index];
		Node<T>* n = front;
		while (index--) {
			n = n->next;
		}
		return n->val;
	}
	void insert(T val) {
		/*v.push_back(val);
		count++;*/
		if (front == null) {
			front = tail = new Node<T>(val, null);
		}
		else {
			tail->next = new Node<T>(val, null);
			tail = tail->next;
		}
		count++;
	}
	void insert(T val, int weight)
	{
		Node<T>* temp, * q;
		temp = new Node<T>(val, null, weight);
		if (front == NULL || weight > front->weight)
		{
			temp->next = front;
			front = temp;
		}
		else
		{
			q = front;
			while (q->next != NULL && q->next->weight >= weight)
				q = q->next;
			temp->next = q->next;
			q->next = temp;
		}
		count++;
	}
	T deQueue()
	{
		Node<T>* temp;
		if (front != NULL)
		{
			temp = front;
			T data = temp->val;
			front = front->next;
			free(temp);
			count--;
			return data;
		}
	}
	bool isEmpty() {
		return (count == 0);
	}
	T top() {
		return front->val;	
	}
	void Delete(T &val) {
		if (front != null && front->val == val) {
			Node<T>* a = front->next;
			delete front;
			front = a;
			count--;
			return;
		}
		Node<T>* prev = null;
		Node<T>* t = front;
		while (t != null) {
			prev = t;
			t = t->next;
			if (t != null && t->val == val) {
				prev->next = t->next;
				delete t;
				count--;
				break;
			}
		}
	}
};
