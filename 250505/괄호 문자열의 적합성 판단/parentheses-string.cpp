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
    }

    if (s.empty() == false) cout << "No";
    else if (s.empty() == true) cout << "Yes";

    
    
}