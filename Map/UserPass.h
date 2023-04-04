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
			userPass.emplace(username, password);
		}
		else {
			cout << "Username already exists";
		}
		//userPass.emplace(username, password);
		cout << "New login. Username: " << username << " Password: " << userPass[username] << endl;
	}

	bool login(string username, string password) {
		if (userPass[username] == password) {
			return true;
		}
		else {
			return false;
		}
	}
};
