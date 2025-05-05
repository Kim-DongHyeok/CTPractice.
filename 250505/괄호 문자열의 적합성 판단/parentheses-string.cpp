#include <iostream>
#include <stack>

using namespace std;

string str;

int main() {
    cin >> str;

    stack<int> s;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            s.push('(');
        }
        else if (str[i] == ')') {
            s.pop();
        }
        else if (s.empty() == true && str[i] == ')') {
            cout << "No";
            return 0;
        }
    }

    if (s.empty() == false) cout << "No";
    else cout << "Yes";

    return 0;
}