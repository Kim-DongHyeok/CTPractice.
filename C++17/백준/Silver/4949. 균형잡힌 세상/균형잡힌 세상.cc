#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main() {
	stack<char> count;
	int ch = 0;

	string sen;

	while (true) {
		getline(cin, sen);

		if (sen == ".") return 0;


		for (int i = 0; i < sen.length(); i++) {
			if (sen[i] == '(') {
				count.push('(');
			}
			else if (sen[i] == '[') {
				count.push('[');
			}
			else if (count.empty() == false) {
				if (sen[i] == ')' && count.top() == '(') {
					count.pop();
				}
				else if (sen[i] == ')') {
					count.push(')');
				}
				else if (sen[i] == ']' && count.top() == '[') {
					count.pop();
				}
				else if (sen[i] == ']') {
					count.push(']');
				}
			}
			else if (count.empty() == true) {
				if (sen[i] == ')' || sen[i] == ']') {
					cout << "no\n";
					ch = 1;
					break;
				}
			}
		}

		if (count.empty() == false && ch != 1) {
			cout << "no\n";
			while (count.empty() == false) count.pop();
		}
		else if (ch != 1) cout << "yes\n";

		ch = 0;
	}
}