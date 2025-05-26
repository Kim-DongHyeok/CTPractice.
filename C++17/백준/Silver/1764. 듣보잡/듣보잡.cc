#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string n[500000];
string m[500000];
string result[500000];

int main() {
	int N, M;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> n[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> m[i];
	}

	sort(n, n+N);


	int count = 0;

	for (int i = 0; i < M; i++) {
		if (binary_search(n, n + N, m[i])==true) {
			result[count] = m[i];
			count++;
		}
	}
	
	cout << count << "\n";
    sort(result, result + count);
	for (int i = 0; i < count; i++) {
		cout << result[i] << "\n";
	}
}