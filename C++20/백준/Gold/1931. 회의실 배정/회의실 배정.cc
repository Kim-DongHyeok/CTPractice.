#include <iostream>
#include <cmath>
#include<algorithm> 
#include <vector>
using namespace std;

vector<pair<int, int>> during;
vector<pair<int, int>> result;


int main() {

	int N, f, l;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> f >> l;
		during.push_back(make_pair(f, l));
	}

	sort(during.begin(), during.end(), [](pair<int, int> first, pair<int, int> last) {
    	if (first.second == last.second) return first.first < last.first;
    	else
    		return first.second < last.second;
	});

	/*for (int i = 0; i < N; i++) {
		cout << during[i].first << " " << during[i].second << endl;
	}*/

	result.push_back(make_pair(during[0].first, during[0].second));
	int iterator=0;

	for (int i = 1; i < N; i++) {
		if (during[i].first >= result[iterator].second) {
			result.push_back(make_pair(during[i].first, during[i].second));
			iterator++;
		}
	}

	cout << iterator+1;

  return 0;
}