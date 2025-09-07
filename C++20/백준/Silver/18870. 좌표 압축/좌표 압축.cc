#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>


using namespace std;

pair<int, int> p[1000000];

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> p[i].second;

		p[i].first = i;
	}

	sort(p, p + N, [](pair<int, int> a, pair<int, int> b) {	return a.second < b.second;});//실제 값 기준 정렬
	 
	int cnt = 0;

	for (int i = 0; i < N; i++) {//실제 값 삭제 후 인덱스 정보 기록 / 연속된 값일 경우 같은 값. i 말고 cnt 변수?
		
		if (i == N - 1) {
			p[i].second = cnt;
		}
		else if (p[i].second == p[i + 1].second) {
			p[i].second = cnt;
		}
		else {
			p[i].second = cnt;
			cnt++;
		}
	
	}

	sort(p, p + N, [](pair<int, int> a, pair<int, int> b) {return a.first < b.first; });//first 값으로 원래 순서 복구
	
	for (int i = 0; i < N; i++) {
		cout << p[i].second << " ";
	}
	
}
