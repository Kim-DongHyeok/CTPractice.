#include <iostream>
using namespace std;

int a[12]; 

int main() {
	int T, n;
	cin >> T;

	a[1] = 1;
	a[2] = 2;
	a[3] = 4;

	for (int i = 4; i <= 11; i++) {
		a[i] = a[i-1] + a[i-2] + a[i-3];
	}

	while (T--) {
		cin >> n;
		cout << a[n] << '\n';
	}

	return 0;
}
