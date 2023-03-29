#pragma once
#include<iostream>
#include<vector>

using namespace std;
template <class T>
class Stack {
private:
	vector<T> v;
public:
	int count = 0;
	Stack() {}

	void push(T val) {
		count++;
		v.push_back(val);
	}
	T top() {
		return *(v.end() -1);
	}
	void pop() {
		if (v.size() != 0) {
			count--;
			v.pop_back();
		}
	}
	bool isEmpty() {
		return (count == 0);
	}
};