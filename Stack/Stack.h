#pragma once
#include <list>
using namespace std;

template <typename T>
class Stack {
private:
	list<T> internalList;
public:
	void push(T element) {
		internalList.push_front(element);
	}

	T top() {
		if (!this->isEmpty()) {
			return internalList.begin();
		}
		else {
			throw "List is empty";
		}
	}

	void pop() {
		if (!this->isEmpty()) {
			internalList.pop_front();
		}
	}

	bool isEmpty() {
		return internalList.empty();
	}
};