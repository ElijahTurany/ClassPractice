#pragma once
#include <iostream>

class Table {
private:
	int data[10]{ NULL };
public:
	void add(int index, int numIn) {
		if (data[index % 10] == NULL) {
			data[index % 10] = numIn;
			cout << "Item inserted normally" << endl;
		}
		else {
			for (int i = 0; i < 10; i++) {
				if (data[((index % 10) + (i * i)) % 10] == NULL) {
					data[((index % 10) + (i * i)) % 10] = numIn;
					cout << "Item inserted using probing" << endl;
					break;
				}
			}
		}
	}

	void printTable() {
		cout << "[";
		for (int i = 0; i < 10; i++) {
			cout << data[i] << " ";
		}
		cout << "]";
	}
};