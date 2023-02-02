#include <iostream>
using namespace std;
#include "MyGrid.h"

int main() {
    Grid grid;
    grid.printGrid();
    grid.setCell(0, 3, '!');
    grid.printGrid();
    char* ptr{ grid.getCellPtr(0, 3) };
    cout << *ptr << endl;
}
