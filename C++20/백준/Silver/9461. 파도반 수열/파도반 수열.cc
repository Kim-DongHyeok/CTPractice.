#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;


int main() {
	long long arr[101];
	

	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;

	for (int i = 6; i < 101; i++) {
		arr[i] = arr[i - 1] + arr[i - 5];
	}

	/*for (int i = 1; i < 101; i++) {
		cout << arr[i] << "\n";
	}*/

	int t, tt;

	cin >> t;

	for(int i = 0; i < t; i++) {
		cin >> tt;
		cout << arr[tt] << "\n";
	}
}