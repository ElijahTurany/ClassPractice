#include <iostream>
#include <vector>
#include "MergeSort.h"
using namespace std;

int main() {
	MergeSort m;
	vector<int> vec{ 2, 1, 3, 4, 5, 6 };
	vector<int> vec2 = m.Sort(vec);

	/*for (int i = 0; i < vec2.size(); i++) {
		cout << vec2[i];
	}*/
}