#pragma once
#include <iostream>
using namespace std;

class Animal {
public:
	Animal() {
		cout << "Animal" << endl;
	}
};

class Pet : virtual public Animal {
public:
	Pet() {
		cout << "Pet" << endl;
	}
};

class Hunter : virtual public Animal {
public:
	Hunter() {
		cout << "Hunter" << endl;
	}
};

class Cat : virtual public Pet, Hunter {
public:
	Cat() {
		cout << "Cat" << endl;
	}
};