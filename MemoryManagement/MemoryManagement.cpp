#include <iostream>
#include <vector>
#include "CustomInt.h"
using namespace std;

void tempFunction() {
    vector<int>* myVec = new vector<int>;
    delete myVec;
    myVec = nullptr;
    //cout << myVec->size();
}

void temp2() {
    PairOfInts pi;
    PairOfInts p2{ pi };
}

int main() {
    //tempFunction();
    temp2();
}
