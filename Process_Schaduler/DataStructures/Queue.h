#pragma once
#include<iostream>
#include<vector>
using namespace std;
template <class T>
class Queue {
private:
	vector<T> v;
public:
	int count = 0;

	void enQueue(T val) {
		count++;
		v.push_back(val);
	}
	T top() {
		return *v.begin();
	}
	void deQueue() {
		if (v.size() != 0) {
			count--;
			v.erase(v.begin());
		}
	}
	bool isEmpty() {
		return (count == 0);
	}
};