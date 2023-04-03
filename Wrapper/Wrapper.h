#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class PrintableVector {
private:
	vector<T> data;

public:
	PrintableVector() {}

	int size() {
		return data.size();
	}

	void append(T item) {
		data.push_back(item);
	}

	T pop() {
		T toReturn = data[data.size() - 1];
		data.pop_back();
		return toReturn;
	}

	void print() {
		for (int i = 0; i < data.size(); i++) {
			cout << data[i] << " ";
		}
	}

	template <typename T>
	friend ostream& operator<<(ostream& out, const PrintableVector<T>& vec);
};

template <typename T>
ostream& operator<<(ostream& out, const PrintableVector<T>& vec) {
	out << "[ ";
	for (T item : vec.data) {
		out << item << " ";
	}
	out << "]";
	return out;
}