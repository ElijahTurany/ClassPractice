#pragma once

template <typename Type>
class CustomArrayList {
	private:
		Type data[10];
		int size{ 0 };
		int capacity{ 10 };
	public:
		CustomArrayList() {}
		 
		Type at(int index) {
			if ((index < size) && (index >= 0)) {
				return data[index];
			}
			throw "Out of bounds";
		} 

		void set(int index, Type value) {
			if ((index < size) && (index >= 0)) {
				data[index] = value;
			}
			else {
				throw "Out of bounds";
			}
		}
		
		int getSize() {
			return size;
		}

		void append(Type value) {
			if (size < capacity) {
				data[size] = value;
				size++;
			}
			else {
				throw "Array full";
			}
		}
};

