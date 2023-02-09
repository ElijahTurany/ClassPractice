#include "CustomArrayList.h"
#include <iostream>
using namespace std;

void runTestOne() {
	cout << "Running tests" << endl;
	CustomArrayList<int> customArray1;
	customArray1.append(1);
	customArray1.append(6);
	customArray1.append(15);
	if (customArray1.getSize() != 3) {
		cout << "Size is incorrect" << endl;
	}

	CustomArrayList<int> customArray2;
	customArray2.append(1);
	customArray2.append(6);
	customArray2.append(15);
	if ((customArray2.at(0) != 1) || (customArray2.at(1) != 6) || (customArray2.at(2) != 15)) {
		cout << "Appended data is incorrect" << endl;
	}

	CustomArrayList<int> customArray3;
	try {
		for (int i = 0; i < 12; i++) {
			customArray3.append(i);
		}
		cout << "Appending over capacity didn't throw exception" << endl;
	}
	catch (...) {}

	CustomArrayList<int> customArray4;
	try {
		int van = customArray4.at(-1);
		cout << "Accessing negative index didn't throw exception" << endl;
	}
	catch (...) {}
}

void runTestTwo() {
	CustomArrayList<char> c;
	c.append('i');
	c.append('n');
	c.append('d');
	c.append('e');
	c.append('x');
	cout << c;

}

int main() {
	runTestTwo();
}

