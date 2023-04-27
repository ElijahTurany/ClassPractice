#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Graph {
private:
	vector<vector<bool>> matrix;
public:
	Graph(int size) {
		vector<bool> vec(size, false);
		for (int i = 0; i < size; i++) {
			matrix.push_back(vec);
		}
	}

	void addConnection(int a, int b) {
		matrix[a][b] = true;
		matrix[b][a] = true;
	}

	void addConnection(int a, vector<int> b) {
		for (int i = 0; i < b.size(); i++) {
			matrix[a][b[i]] = true;
			matrix[b[i]][a] = true;
		}
	}

	void printMatrix() {
		cout << "    ";
		for (int i = 0; i < matrix.size(); i++) {
			if (i / 10 == 0) {
				cout << "  ";
			}
			else {
				cout << i / 10 << " ";
			}
		}
		cout << endl << "    ";
		for (int i = 0; i < matrix.size(); i++) {
			cout << i % 10 << " ";
		}
		cout << endl << "   -";
		for (int i = 0; i < matrix.size(); i++) {
			cout << "--";
		}
		cout << endl;

		for (int i = 0; i < matrix.size(); i++) {
			if (i < 10) {
				cout << " ";
			}
			cout << i << "| ";
			for (int j = 0; j < matrix.size(); j++) {
				if (matrix[i][j]) {
					cout << "X ";
				}
				else {
					cout << "  ";
				}
			}
			cout << "|" << endl;
		}
		cout << "   -";
		for (int i = 0; i < matrix.size(); i++) {
			cout << "--";
		}
		cout << endl;
	}

	bool findPath(int a, int b) {
		if (a >= matrix.size() || b >= matrix.size() || a < 0 || b < 0) {
			return false;
		}
		if (matrix[a][b]) {
			return true;
		}
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
		}
		return recursiveHelper(queue[0], b, queue, visited);
	}

	bool recursiveHelper(int a, int b, vector<int> queue, bool visited[10]) {
		if (matrix[a][b]) {
			return true;
		}
		queue.erase(queue.begin());
		visited[a] = true;

		for (int i = 0; i < 10; i++) {
			if (matrix[a][i] && !visited[i]) {
				queue.push_back(i);
			}
		}
		if (queue.size() == 0) {
			return false;
		}
		else {
			return recursiveHelper(queue[0], b, queue, visited);
		}
	}

	/*int findDistance(int a, int b) {
		if (a >= matrix.size() || b >= matrix.size() || a < 0 || b < 0) {
			return -1;
		}
		if (matrix[a][b]) {
			return 1;
		}
		if (a==b && matrix[a][b]) {
			return 0;
		}
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
		}
		return recursiveHelper(queue[0], b, queue, visited);
	}

	int distanceHelper(int a, int b, vector<int> queue, bool visited[10]) {
		if (matrix[a][b]) {
			return 1;
		}
		queue.erase(queue.begin());
		visited[a] = true;

		for (int i = 0; i < 10; i++) {
			if (matrix[a][i] && !visited[i]) {
				queue.push_back(i);
			}
		}
		if (queue.size() == 0) {
			return -1;
		}
		else {
			return 1 + distanceHelper(queue[0], b, queue, visited);
		}
	}*/
};