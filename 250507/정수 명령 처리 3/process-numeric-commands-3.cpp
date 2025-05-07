#include <iostream>
#include <deque>

using namespace std;
int N;
string cmd[10000];
int num[10000];

int main() {
    deque<int> s;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> cmd[i];
        if (cmd[i] == "push_front" || cmd[i] == "push_back") {
            cin >> num[i];
        }
    }

    for (int i = 0; i < N; i++) {
        if (cmd[i] == "push_front") {
            s.push_front(num[i]);
        }
        else if (cmd[i] == "push_back") {
            s.push_back(num[i]);
        }
        else if (cmd[i] == "pop_front") {
            cout << s.front() << endl;
            s.pop_front();
        }
        else if (cmd[i] == "pop_back") {
            cout << s.back() << endl;
            s.pop_back();
        }
        else if (cmd[i] == "size") {
            cout << s.size() << endl;
        }
        else if (cmd[i] == "empty") {
            cout << (int)s.empty() << endl;
        }
        else if (cmd[i] == "front") {
            cout << s.front() << endl;
        }
        else if (cmd[i] == "back") {
            cout << s.back() << endl;
        }
    }

    return 0;
}