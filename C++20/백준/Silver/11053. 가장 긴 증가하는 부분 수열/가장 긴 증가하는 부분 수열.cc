#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, c;

int arr[1000];
int d[1000];

int Count(int i);

vector<int> result;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

    if (N == 1) {
    	cout << 1;
    	return 0;
    }

	d[0] = 1;

	int answer = 0;

	for (int i = 1; i < N; i++) {
		d[i] = Count(i);

		if (answer < d[i]) answer = d[i];
	}

	cout << answer;
}

int Count(int i) {
	int result = 1;

	for (int a = i - 1; a > -1; a--) {
		if (arr[a]<arr[i] && d[a] + 1 > result) result = d[a] + 1;
	}

	return result;
}