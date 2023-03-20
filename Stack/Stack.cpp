using namespace std;
#include <iostream>
#include "Stack.h"

int main() {
	Stack<string> myStack;
	myStack.push("a");
	myStack.push("b");
	myStack.push("c");
	myStack.push("d");
	cout << myStack.top();
	myStack.pop();
}