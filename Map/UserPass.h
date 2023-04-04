#pragma once
using namespace std;
#include <iostream>
#include <map>

class UserPass {
private:
	map<string, string> userPass;
public:
	void addPair(string username, string password) {
		if (userPass[username] == "") {
			userPass[username] = password;
			cout << "New login. Username: " << username << " Password: " << userPass[username] << endl;
		}
		else {
			cout << "Username already exists" << endl;
		}
	}

	bool login(string username, string password) {
		if (password == "") {
			cout << "Please enter a password" << endl;
		}
		else if (userPass[username] == password) {
			cout << "Login successful" << endl;
			return true;
		}
		else {
			cout << "Login failed" << endl;
			return false;
		}
	}
};
