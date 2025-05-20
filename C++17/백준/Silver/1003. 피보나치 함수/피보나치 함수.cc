#include <iostream>

using namespace std;

int a[41] = { 0 };
int b[41] = { 0 };


int main() {
	int T, N;

	a[0] = 1;
	a[1] = 0;
	b[0] = 0;
	b[1] = 1;

	for (int i = 2; i < 41; i++) {
		a[i] = a[i - 1] + a[i - 2];
		b[i] = b[i - 1] + b[i - 2];
	}

	cin >> T;

	for (int i = 0; i < T; i++)	{
		cin >> N;

		cout << a[N] << " " << b[N] << "\n";
	}
}