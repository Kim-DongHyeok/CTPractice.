#include <iostream>
#include <deque>
#include <algorithm>
#include <stack>

using namespace std;

int age[100000];
string name[100000];

int idx[100000];

bool idxsort(int a, int b) {
	a = age[a];
	b = age[b];

	if (a == b) return a < b;
	else if (a < b) return true;
	else return false;
}

int main() {
	int N;
	cin >> N;



	for (int i = 0; i < N; i++) {
		cin >> age[i] >> name[i];
	}

	for (int i = 0; i < N; i++) {
		idx[i] = i;
	}

	stable_sort(idx, idx + N, idxsort);
	
	for (int i = 0; i < N; i++) {
		cout << age[idx[i]] << ' ' << name[idx[i]] << endl;
	}



}