using namespace std;
#include "Item.h"
#include <iostream>

int main() {
	Sword s{ "sword", 4.4, 18, 5.3, 1.9 };
	s.attack();
	s.hold();
	s.attack();

	Shield sh{ "shield", 8, 14, 22};
	sh.equip();
	sh.hold();
	sh.equip();
}