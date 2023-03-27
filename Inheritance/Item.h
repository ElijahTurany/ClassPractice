#pragma once
#include <string>
#include <iostream>
using namespace std;

class Item {
protected:
	string name;
	double weight;
	int cost;
	bool held;

public:
	Item(string n, double w, int c) {
		name = n;
		weight = w;
		cost = c;
		held = false;
	}

	void hold() {
		cout << "You are now holding " << name << ". It weighs " << weight << endl;
		held = true;
	}
};

class Sword : public Item {
private:
	double damage;
	double speed;

public:
	Sword(string n, double w, int c, double d, double s) : Item(n, w, c) {
		damage = d;
		speed = s;
	}
	void attack() {
		if (held) {
			cout << "Enemy attacked, " << damage << " damage dealt" << endl;
		}
		else {
			cout << "You are not holding " << name << endl;
		}
	}
};

class Shield : public Item {
private:
	double defense;
	
public:
	Shield(string n, double w, int c, double d) : Item(n, w, c) {
		defense = d;
	}

	void equip() {
		if (held) {
			cout << name << " equipped" << endl;
		}
		else {
			cout << "You are not holding " << name << endl;
		}
		
	}
};