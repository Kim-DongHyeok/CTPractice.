#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[1000][3];



int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	
	vector<int> R, G, B;

	R.push_back(arr[0][0]); //i-1의 rgb값
	G.push_back(arr[0][1]);
	B.push_back(arr[0][2]);

	int min = 1001;

	for (int i = 1; i < N; i++) {
		if (G[i - 1] < B[i - 1]) R.push_back(arr[i][0] + G[i - 1]);
		else R.push_back(arr[i][0] + B[i - 1]);

		if (R[i - 1] < B[i - 1]) G.push_back(arr[i][1] + R[i - 1]);
		else G.push_back(arr[i][1] + B[i - 1]);

		if (G[i - 1] < R[i - 1]) B.push_back(arr[i][2] + G[i - 1]);
		else B.push_back(arr[i][2] + R[i - 1]);
	}

	if (R[N - 1] < B[N - 1]) {
		if (R[N - 1] < G[N - 1]) cout << R[N - 1];
		else cout << G[N - 1];
	}
	else {
		if (B[N - 1] < G[N - 1]) cout << B[N - 1];
		else cout << G[N - 1];
	}
	
}