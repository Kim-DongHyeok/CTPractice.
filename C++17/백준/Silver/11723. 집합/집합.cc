#include <iostream>
#include <deque>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int M;
	int ch[21] = { 0 }, N;
	string cmd;

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> cmd;

		if (cmd == "add" || cmd=="remove") {
			cin >> N;
		}
		else if (cmd == "check" || cmd == "toggle") {
			cin >> N;
		}

		if (cmd == "add" && ch[N]!=1) {
			ch[N] = 1;
		}
		else if (cmd == "remove" && ch[N] == 1) {
			ch[N] = 0;
		}
		else if (cmd == "check") {
			cout << ch[N] << "\n";
		}
		else if (cmd=="toggle") {
			if (ch[N] == 1) ch[N] = 0;
			else ch[N] = 1;
		}
		else if (cmd == "all") {
			for (int i = 1; i < 21; i++) {
				ch[i] = 1;
			}
		}
		else if (cmd == "empty") {
			for (int i = 1; i < 21; i++) {
				ch[i] = 0;
			}
		}
	}
}