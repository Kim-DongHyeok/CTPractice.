#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

bool arr[1000001];


int main() {
	int a, b;

	cin >> a >> b;

	for (int i = 2; i <= b; i++) arr[i] = true;

	for (int i = 2; i <= b; i++) {
		if (arr[i] == false) continue;
		
		for (int j = 2; j * i < 1000001; j++) {
			arr[i * j] = false;
		}
	}

	for (int i = a; i <= b; i++) {
		if (arr[i] == true) cout << i << "\n";
	}
}