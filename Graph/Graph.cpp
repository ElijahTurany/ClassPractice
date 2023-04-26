#include <iostream>
#include "Graph.h"
using namespace std;

int main() {
    Graph g;
    g.addConnection(0, 1);
    g.addConnection(1, 2);
    g.addConnection(1, 3);
    g.addConnection(1, 4);
    g.addConnection(2, 3);
    g.addConnection(2, 5);
    g.addConnection(4, 6);
    g.addConnection(4, 7);
    g.addConnection(5, 6);
    g.addConnection(6, 7);
    g.addConnection(8, 9);
    g.printMatrix();
    cout << g.findPath(0, 1) << g.findPath(0, 8) << g.findPath(2, 4) << g.findPath(8, 9) << g.findPath(8, 3);
}