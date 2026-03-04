#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
	unordered_map<string, int> Count;

	string trash, name;

	int test, ct=0;

	cin >> test;

	while (ct < test) {
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> trash >> name;

			Count.insert({ name, 0 });
			Count[name]++;
		}

		
		int tem = 1;

		for (const auto& pair : Count) {
			
			tem = (pair.second + 1) * tem;
		}

		cout << tem-1 << "\n";

		Count.clear();
		
		ct++;
	}
}