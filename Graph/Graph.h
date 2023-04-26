#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Graph {
private:
	bool matrix[10][10];
public:
	Graph() {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				matrix[i][j] = false;
			}
		}
	}

	void addConnection(int a, int b) {
		matrix[a][b] = true;
		matrix[b][a] = true;
	}

	void printMatrix() {
		cout << "   0 1 2 3 4 5 6 7 8 9" << endl << "  ---------------------" << endl;
		for (int i = 0; i < 10; i++) {
			cout << i << "| ";
			for (int j = 0; j < 10; j++) {
				if (matrix[i][j]) {
					cout << "X ";
				}
				else {
					cout << "  ";
				}
			}
			cout << "|" << endl;
		}
		cout << "  ---------------------" << endl;
	}

	bool findPath(int a, int b) {
		bool visited[10];
		vector<int> queue;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				visited[i] = false;
			}
		}
		visited[a] = true;
		for (int i = 0; i < 10; i++) {
			if (matrix[a][i]) {
				queue.push_back(i);
			}
			if (matrix[a][b]) {
				return true;
			}
		}
		return recursiveHelper(queue[0], b, queue, visited);
	}

	bool recursiveHelper(int a, int b, vector<int> queue, bool visited[10]) {
		queue.erase(queue.begin());
		visited[a] = true;

		for (int i = 0; i < 10; i++) {
			if (matrix[a][i] && !visited[i]) {
				queue.push_back(i);
			}
			if (matrix[a][b]) {
				return true;
			}
		}
		if (queue.size() == 0) {
			return false;
		}
		else {
			return recursiveHelper(queue[0], b, queue, visited);
		}
	}
};