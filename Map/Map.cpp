#include <iostream>
#include <map>
#include <string>
#include "UserPass.h"
using namespace std;

int main() {
   /* map<int, string> m;
    m.emplace(6, "marker");
    cout << m[6] << endl;
    m.insert(pair<int, string>(10, "eraser"));
    cout << m[10] << endl;
    cout << m[9] << endl;
    map<int, int> m2;
    cout << m2[200] << endl;

    m.emplace(6, "exit");
    m.insert(pair<int, string>(6, "exit"));
    cout << m[6] << endl;

    m[6] = "exit";
    cout << m[6] << endl;

    m[1] = "pencil";
    cout << m[1] << endl;*/
    UserPass up;
    up.addPair("123", "abc");
    up.addPair("username", "password");
    up.addPair("John", "sparky09");
    up.addPair("John", "password");
    
    cout << up.login("123", "abc") << endl << up.login("username", "passwodr");
}