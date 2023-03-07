#include <iostream>
using namespace std;

void firstRecursion() {
	cout << "Called";
	firstRecursion();
	cout << "Done";
}

void countdown(int x) {
	if (x == 0) {
		cout << "Liftoff";
		return;
	}

	cout << x << " ";
	countdown(x - 1);
}

int main() {
	countdown(10);
}