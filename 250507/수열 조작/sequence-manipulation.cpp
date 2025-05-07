#include <iostream>
#include <deque>

using namespace std;

int main() {
	int N;
    cin >> N;

	deque<int> s; 

	for (int i = 1; i <= N; i++) {
		s.push_back(i);
	}

	while (s.size() != 1) {
		s.pop_front();
		s.push_back(s.front());
		s.pop_front();
	}

	cout << s.front();
}
