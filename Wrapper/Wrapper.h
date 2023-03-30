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
		return data.size()
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
	friend ostream& operator<<(ostream& out, const PrintableVector& vec);
};

ostream& operator<<(ostream& out, PrintableVector& vec) {
	for (int i = 0; i < vec.size(); i++) {
		out << vec[i] << " ";
	}
	return out;
}