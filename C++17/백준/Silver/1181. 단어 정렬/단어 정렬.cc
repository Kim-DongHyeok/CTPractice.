#include <iostream>
#include <deque>
#include <algorithm>
#include <stack>

using namespace std;

int len[200000];
string str[200000];

int idx[200000];

bool idxsort_y(int a, int b) {
	string A = str[a];
	string B = str[b];

	if (A < B) return true;
	else return false;
}

bool idxsort(int a, int b) {
	int len1, len2;

	len1 = len[a];
	len2 = len[b];

	if (len1 == len2) return idxsort_y(a, b);

	else if (len1 < len2) return true;
	else return false;
}

int main() {
	int N;
	cin >> N;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(0);

	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}

	for (int i = 0; i < N; i++) {
		len[i] = str[i].length();
	}

	for (int i = 0; i < N; i++) {
		idx[i] = i;
	}

	sort(idx, idx + N, idxsort);

	for (int i = 0; i < N-1; i++) {
		if (str[idx[i]] == str[idx[i + 1]]) {
			continue;
		}
		else cout << str[idx[i]] << "\n";
	}

	cout << str[idx[N - 1]];
}