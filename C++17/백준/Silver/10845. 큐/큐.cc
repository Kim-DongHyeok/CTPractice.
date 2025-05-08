#include <iostream>
#include <queue>

using namespace std;

int N;
string command[10000];
int value[10000];

int main() {
    cin >> N;

    queue<int> s;

    for (int i = 0; i < N; i++) {
        cin >> command[i];
        if (command[i] == "push") {
            cin >> value[i];
        }
    }

    for (int i = 0; i < N; i++) {
        if (command[i] == "push") {
            s.push(value[i]);
        }
        else if (command[i] == "pop") {
            if(s.empty()==true){
                cout << -1 << endl;
            }
            else{
                cout << s.front() << endl;
                s.pop();
            }
        }
        else if (command[i] == "size") {
            cout << s.size() << endl;
        }
        else if (command[i] == "empty") {
            cout << (int)s.empty() << endl;
        }
        else if (command[i] == "front") {
            if(s.empty()==true){
                cout << -1 << endl;
            }
            else{
                cout << s.front() << endl;
            }
        }
        else if (command[i] == "back") {
            if(s.empty()==true){
                cout << -1 << endl;
            }
            else{
                cout << s.back() << endl;
            }
        }
        
    }

    return 0;
}