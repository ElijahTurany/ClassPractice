#pragma once
#include <vector>
using namespace std;

class MergeSort {
private:
public:
	vector<int> Sort(vector<int> data) {
		if (data.size() < 2) {
			return data;
		}
		vector<int> dataL;
		vector<int> dataR;
		cout << "[";
		for (int i = 0; i < data.size()/2; i++) {
			dataL.push_back(data[i]);
			cout << data[i] << " ";
		}
		for (int i = data.size()/2; i < data.size(); i++) {
			dataR.push_back(data[i]);
			cout << data[i] << " ";
		}
		cout << "]" << endl;
		vector<int> left = Sort(dataL);
		vector<int> right = Sort(dataR);

		int leftIndex = 0; int rightIndex = 0;
		vector<int> output;
		while (leftIndex < left.size() && rightIndex < right.size()) {
			if (left[leftIndex] > right[rightIndex]) {
				output.push_back(left[leftIndex]);
				leftIndex++;
			}
			else {
				output.push_back(right[rightIndex]);
				rightIndex++;
			}
		}
		if (leftIndex == left.size()) {
			for (int i = rightIndex; i < right.size(); i++) {
				output.push_back(right[rightIndex]);
			}
		}
		else {
			for (int i = rightIndex; i < right.size(); i++) {
				output.push_back(left[leftIndex]);
			}
		}

		return output;
	}
};