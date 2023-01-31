#include <iostream>
#include "ClassPractice.h"
using namespace std;

void pointerExperiment();
void makeEven(int* input);
void fixWithReference(int& x);

int main() {
    LinkedList list;
    list.createNode(1);
    list.createNode(2);
    list.createNode(3);
    list.createNode(4);
    list.createNode(5546);
    list.printList();

}

void pointerExperiment() {
    int x = 5;
    int* xptr = &x;
    x = 6;
    fixWithReference(x);
    cout << x;
}

void makeEven(int* input) {
    if ((*input % 2) == 1) {
        *input *= 2;
    }
}

void fixWithReference(int& x) {
    if ((x % 2) == 1) {
        x++;
    }
}
