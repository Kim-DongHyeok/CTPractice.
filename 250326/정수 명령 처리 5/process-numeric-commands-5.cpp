#include <iostream>
#include <vector>

using namespace std;

int N;
string command[10000];
int num[10000];

int main() {
    cin >> N;

    vector<int> arr;

    for (int i = 0; i < N; i++) {
        cin >> command[i];
        if (command[i] == "push_back" || command[i] == "get") {
            cin >> num[i];
        }
    }

    for (int i = 0; i < N; i++) {
        if (command[i] == "push_back") {
            arr.push_back(num[i]);
        }
        else if (command[i] == "get") {
            cout << arr[num[i] - 1] << endl;
        }
        else if (command[i] == "pop_back") {
            arr.pop_back();
        }
        else if (command[i] == "size") {
            cout << arr.size() << endl;
        }

    }
}
