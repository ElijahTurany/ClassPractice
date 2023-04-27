#include <iostream>
#include "Graph.h"
using namespace std;

int main() {
    Graph g(10);
    g.addConnection(0, 1);
    g.addConnection(1, vector<int>{2, 3, 4});
    g.addConnection(2, vector<int>{3, 5});
    g.addConnection(4, vector<int>{6, 7});
    g.addConnection(5, 6);
    g.addConnection(6, 7);
    g.addConnection(8, 9);
    g.printMatrix();
    cout << g.findPath(0, 1) << g.findPath(0, 8) << g.findPath(2, 4) << g.findPath(8, 9) << g.findPath(8, 3) << endl;
    //cout << g.findDistance(0, 1) << g.findDistance(0, 2);
}