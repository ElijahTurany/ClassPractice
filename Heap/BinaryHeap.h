#pragma once
class maxHeap {
private:
	int data[100]; //Oversized array, assume we aren't running out!
	int size{ 0 };
	//Recursive function
	void reheapifyUp(int index) {
		//Base case
		if (index <= 1) {
			return; //New item is already the root!
		}
		//Recursive case
		if (data[index / 2] >= data[index]) {
			return; //No ordering violation!
		}
		else {
			int tmp = data[index];
			data[index] = data[index / 2];
			data[index / 2] = tmp;
			reheapifyUp(index / 2); //recursive call
		}
	}

	void reheapifyDown(int index) {
		if (index * 2 > size) {return;}
		if ((data[index] >= data[index * 2]) && (data[index] >= data[index * 2 + 1])) {return;}
		if (index * 2 == size) {
			if (data[index] < data[index * 2]) {
				int tmp = data[index];
				data[index] = data[index * 2];
				data[index * 2] = tmp;
			}
			return;
		}

		if (data[index * 2] >= data[index * 2 + 1]) {
			int tmp = data[index];
			data[index] = data[index * 2];
			data[index * 2] = tmp;
			reheapifyDown(index * 2);
		}
		else {
			int tmp = data[index];
			data[index] = data[index * 2 + 1];
			data[index * 2 + 1] = tmp;
			reheapifyDown(index * 2 + 1);
		}
	}
public:
	//Default constructor is fine
	void insert(int x) {
		//Fix the shape constraint first
		data[size + 1] = x;
		//Then the ordering constraint
		reheapifyUp(size + 1);
		size++;
	}
	int removeMax() {
		//Fix the shape constraint first
		int returnMe = data[1];
		data[1] = data[size];
		size--;
		//Then the ordering constraint
		reheapifyDown(1);
		return returnMe;
	}
	int getMax() {
	}
	int getSize() { return size; }
};