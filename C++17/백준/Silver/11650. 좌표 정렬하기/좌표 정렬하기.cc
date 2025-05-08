#include <iostream>
#include <deque>
#include <algorithm>
#include <stack>

using namespace std;

int x[100000];
int y[100000];

int idx[100000];

bool idxsort_y(int a, int b) {
	a = y[a];
	b = y[b];

	if (a < b) return true;
	else return false;
}

bool idxsort(int a, int b) {
	int x1, x2;

	x1 = x[a];
	x2 = x[b];

	if (x1 == x2) return idxsort_y(a, b);

	else if (x1 < x2) return true;
	else return false;
}

int main() {
	int N;
	cin >> N;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(0);

	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
	}

	for (int i = 0; i < N; i++) {
		idx[i] = i;
	}

	sort(idx, idx + N, idxsort);

	for (int i = 0; i < N; i++) {
		cout << x[idx[i]] << ' ' << y[idx[i]] << "\n";
	}
}