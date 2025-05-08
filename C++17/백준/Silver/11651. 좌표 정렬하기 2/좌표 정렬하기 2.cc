#include <iostream>
#include <deque>
#include <algorithm>
#include <stack>

using namespace std;

int x[100000];
int y[100000];

int idx[100000];

bool idxsort_y(int a, int b) {
	a = x[a];
	b = x[b];

	if (a < b) return true;
	else return false;
}

bool idxsort(int a, int b) {
	int y1, y2;

	y1 = y[a];
	y2 = y[b];

	if (y1 == y2) return idxsort_y(a, b);

	else if (y1 < y2) return true;
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