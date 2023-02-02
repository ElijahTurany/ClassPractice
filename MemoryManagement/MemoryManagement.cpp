#include <iostream>
#include <vector>
#include "CustomInt.h"
#include "Fraction.h"
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
    //temp2();
    Fraction frac1{ 1,2 };
    Fraction frac2{ 1,4 };
    Fraction frac3 = frac1 * frac2;
    Fraction frac4 = frac1 / frac2;
    Fraction frac5 = frac1 + frac2;
    Fraction frac6 = frac1 - frac2;
    cout << frac3.print() << " " << frac4.print() << " " << frac5.print() << " " << frac6.print();
}
