#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;


int main() {
	int K, A, B;

	cin >> K;

	A = 1;
	B = 0;

	for (int i = 1; i <= K; i++) {
		int temB = B;
		B += A;
		A = temB;
	}

	cout << A << " " << B;
}