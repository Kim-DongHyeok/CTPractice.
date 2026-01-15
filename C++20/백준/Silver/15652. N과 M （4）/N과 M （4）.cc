#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

vector<int> arr;
int N, M;

void backtrack(int interator, int m, int before);
void result(int m);

int main() {

	cin >> N >> M;

	backtrack(1, M, 1);
}

void backtrack(int iterator, int m, int before) {
	if (iterator == m) {
		for (int i = before; i <= N; i++) {
			arr.push_back(i);

			result(m);

			arr.pop_back();
		}

		arr.pop_back();
		return;
	}
	else if (iterator == 1) {
		for (int i = 1; i <= N; i++) {
			arr.push_back(i);

			backtrack(2, m, i);
		}
		return;
	}
	else if (iterator > 1) {
		for (int i = before; i <= N; i++) {
			arr.push_back(i);

			backtrack(iterator + 1, m, i);
		}

		arr.pop_back();
		return;
	}
}

void result(int m) {
	for (int i = 0; i < m; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
}