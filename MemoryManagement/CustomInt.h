#pragma once

class CustomInt {
private:
	int val;
public:
	CustomInt(int i) {
		val = i;
	}
	int get() {
		return val;
	}
	void set(int i) {
		val = i;
	}
};

class PairOfInts {
private:
	CustomInt* first;
	CustomInt* second;
public:
	PairOfInts() {
		first = new CustomInt{ 4 };
		CustomInt* localVar = new CustomInt{ 6 };
		second = localVar;
	}
	~PairOfInts() {
		delete first, second;
	}

	PairOfInts(const PairOfInts& pairIn) {
		first = new CustomInt{ pairIn.first->get() };
		second = new CustomInt{ pairIn.second->get() };
	}

	PairOfInts& operator=(const PairOfInts& pairIn) {
		delete first, second;
		first = new CustomInt{ pairIn.first->get() };
		second = new CustomInt{ pairIn.second->get() };

		return *this;
	}
};