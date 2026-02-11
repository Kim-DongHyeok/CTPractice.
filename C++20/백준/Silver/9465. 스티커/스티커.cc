#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int T, n;
int ct = 0;

int arrup[100000];
int arrdown[100000];

vector<int> up, down;

int main() {
	cin >> T;

	int MAX = 0;

	while (ct < T) {
		ct++;

		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> arrup[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> arrdown[i];
		}

		up.push_back(arrup[0]);
		down.push_back(arrdown[0]);

		down.push_back(arrdown[1] + up[0]);
		up.push_back(arrup[1] + down[0]);

		for (int i = 2; i < n; i++) {
			MAX = max({ up[i - 2], down[i - 1], down[i - 2] });
			up.push_back(arrup[i] + MAX);
			MAX = max({ down[i - 2], up[i - 1], up[i - 2] });
			down.push_back(arrdown[i] + MAX);

			MAX = 0;
		}

		cout << max(up[n - 1], down[n - 1]) << "\n";

		up.clear();
		down.clear();
	}
}