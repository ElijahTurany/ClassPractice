#pragma once
#include <iostream>

template <typename Type>
class CustomArrayList {
	private:
		Type* data;
		int size{ 0 };
		int capacity{ 10 };
	public:
		CustomArrayList() { //O(1)
			data = new Type[capacity];
		}

		~CustomArrayList() { //O(1)
			delete[] data;
		}

		CustomArrayList(const CustomArrayList<Type>& other) { //O(N)
			capacity = other.capacity;
			size = other.size;
			data = new Type[capacity];
			for (int i = 0; i < size; i++) {
				data[i] = other.data[i];
			}
		}

		CustomArrayList operator=(const CustomArrayList<Type>& other) { //O(N)
			delete[] data;
			capacity = other.capacity;
			size = other.size;
			data = new Type[capacity];
			for (int i = 0; i < size; i++) {
				data[i] = other.data[i];
			}
		}
		 
		Type at(int index) { //O(1)
			if ((index < size) && (index >= 0)) {
				return data[index];
			}
			throw "Out of bounds";
		} 

		void set(int index, Type value) { //O(1)
			if ((index < size) && (index >= 0)) {
				data[index] = value;
			}
			else {
				throw "Out of bounds";
			}
		}
		
		int getSize() { //O(1)
			return size;
		}
		
		void append(Type value) { //O(N)
			if (size == capacity) {
				this->expand();
			}
			data[size++] = value;
		}

		void expand() { //O(N)
			Type* tmp = new Type[capacity*2];
			for (int i = 0; i < capacity; i++) {
				tmp[i] = data[i];
			}
			delete[] data;
			data = tmp;
			tmp = nullptr;
			capacity *= 2;
		}

		Type& operator[](int index) { //O(1)
			if ((index < size) && (index >= 0)) {
				return data[index];
			}
			else {
				throw "Out of bounds";
			}
		}

		template <typename Type>
		friend std::ostream& operator<<(std::ostream& out, const CustomArrayList<Type>& myList);
};

template <typename Type>
std::ostream& operator<<(std::ostream& out, const CustomArrayList<Type>& myList) { //O(N)
	out << "[";
	for (int i = 0; i < myList.size; i++) {
		out << myList.data[i] << " ";
	}
	out << "]";
	return out;
}

