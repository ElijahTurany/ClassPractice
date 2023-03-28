using namespace std;
#include "Item.h"
#include <iostream>

int main() {
	Sword s{ "sword", 4.4, 18, 5.3, 1.9 };
	s.attack();
	s.hold();
	s.attack();
	cout << endl;

	Shield sh{ "shield", 8, 14, 22};
	sh.equip();
	sh.hold();
	sh.equip();
	cout << endl;

	//Upcasting
	Item* iptr{ &s };
	Item& iref{ sh };
	iref.hold();
	//Legal downcasting
	Shield* sh2{ dynamic_cast<Shield*>(&iref) };
	sh2->equip();
	cout << endl;

	//Illegal downcasting
	Sword* s2{ dynamic_cast<Sword*>(&sh) };
	cout << s2 << endl;

	Shield& shieldRef{ dynamic_cast<Shield&>(*iptr) };
	cout << &shieldRef << endl;
}