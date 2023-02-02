#pragma once
#include <vector>
using namespace std;

class Grid {
private:
	vector<vector<char>> theGrid;
public:
	Grid() {
		for (int i = 0; i < 4; i++) {
			vector<char> row;
			for (int j = 0; j < 4; j++) {
				row.push_back('#');
			}
			theGrid.push_back(row);
		}
	}
	void setCell(int x, int y, char value) {
		theGrid[y][x] = value;
	}
	char* getCellPtr(int x, int y) {
		return &theGrid[y][x];
	}
	void printGrid() {
		for (int i = 0; i < theGrid.size(); i++) {
			for (int j = 0; j < theGrid.at(i).size(); j++) {
				cout << theGrid[j][i] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
};