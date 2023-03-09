#pragma once
#include <iterator>
#include <cstddef>

class HiddenArray {
private:
	int data[100];
public:
	struct iterator {
		using iterator_category = std::forward_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = int;
		using pointer = value_type*;
		using reference = value_type&;

		iterator(pointer ptr) :p(ptr) {}

		reference operator*() const { return *p; }

		pointer operator->() { return p; }

		iterator& operator++() {
			p++;
			return *this;
		}

		iterator& operator++(int) {
			iterator tmp = *this;
			++(*this);
			return tmp;
		}

		friend bool operator==(const iterator& a, const iterator& b) {

		}

		friend bool operator!=(const iterator& a, const iterator& b) {

		}

	private:
		pointer p;
	};

	iterator begin() { return iterator(&data[0]); }
	iterator end() { return iterator(&data[100]); }
};