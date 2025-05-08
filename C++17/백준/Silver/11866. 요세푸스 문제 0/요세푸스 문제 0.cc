#include <iostream>
#include <deque>

using namespace std;

int main() {
	int N, K;
	deque<int> p;

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		p.push_back(i);
	}

	cout << '<';

	while (p.size() != 1) {
		for (int i = 1; i < K; i++) {
			//cout << p.front() << ' ';
			p.push_back(p.front());
			p.pop_front();
		}

		cout << p.front() << ", ";
		p.pop_front();
	}

	cout << p.front() << '>';
}