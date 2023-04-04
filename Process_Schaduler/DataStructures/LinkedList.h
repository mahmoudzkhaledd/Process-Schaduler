#pragma once
#include<iostream>
#include<vector>

using namespace std;
template <class T>
class List {
private:
	vector<T> v;
public:
	int count = 0;
	List() {}
	T elementAt(int index){
		return v[index];
	}
	void insert(T val) {
		count++;
		v.push_back(val);
	}
	void remove(T val) {
		for (auto it = v.begin(); it != v.end(); ++it) {
			if (*it == val) {
				v.erase(it);
				count--;
				return;
			}
		}
	}
	void printList() {
		for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	}
};