#include <iostream>
#include <string>
#include <list>

using namespace std;

int n, m;
list<char> s;
list<char>::iterator it;
char c;

int main() {
    cin >> n >> m;
    string st;

    cin >> st;

    it=s.begin();


    for (int i = 0; i < n; i++) {
        s.insert(it, st[i]);
    }

    

    it=s.end();
    

    for (int i = 0; i < m; i++) {

        char command;
        cin >> command;
        if (command == 'P') {
            cin >> c;
        }

        if (command == 'L' && it != s.begin()) it--;
        else if (command == 'R' && it != s.end()) it++;
        else if (command == 'P') s.insert(it, c);
        else if (command == 'D' && it !=s.end()) it=s.erase(it);
    }

    for (it = s.begin(); it != s.end(); it++) cout << *it;

    

    return 0;
}