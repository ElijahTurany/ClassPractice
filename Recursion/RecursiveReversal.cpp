#include <vector>
#include <list>
#include <iostream>
using namespace std;

void reversePrint(list<int> original) {
	int size = original.size();
	if (size != 0) {
		cout << original.back() << " ";
		original.pop_back();
		reversePrint(original);
	}
}

void reversePrint2Helper(list<int>& myCopy) {
	if (myCopy.size() != 0) {
		cout << myCopy.back() << " ";
		myCopy.pop_back();
		reversePrint(myCopy);
	}
}

void reversePrint2(list<int> copy) {
	reversePrint2Helper(copy);
}

void reversePrint3Helper(list<int>& original, list<int>::iterator iter) {
	cout << *iter << " ";
	if (iter == original.begin()) {
		return;
	}
	iter--;
	reversePrint3Helper(original, iter);
}

void reversePrint3(list<int>& original) {
	if (original.size() != 0) {
		list<int>::iterator iter = original.end();
		iter--;
		reversePrint3Helper(original, iter);
		cout << endl;
	}
}

int main() {
	list<int> li{ 2, 5, 7, 10, 22, 24 };
	list<int> li2{ 2 };
	list<int> li3{};

	/*list<int>::iterator iter = li.begin();
	iter++;
	cout << *iter;
	*iter = 8;
	while (iter != li.end()) {
		iter++;
	}

	list<int>::iterator iter2 = li.end();
	iter2--;
	cout << *iter2;*/
	
	reversePrint3(li);
	reversePrint3(li2);
	reversePrint3(li3);
}