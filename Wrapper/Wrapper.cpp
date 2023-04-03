#include <iostream>
#include "Wrapper.h"
using namespace std;

int main() {
    PrintableVector<int> vec;
    vec.append(1);
    vec.append(2);
    vec.append(3);
    vec.append(4);
    cout << vec;
}