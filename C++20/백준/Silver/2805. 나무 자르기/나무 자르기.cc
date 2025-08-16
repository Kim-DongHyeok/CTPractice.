#include <iostream>

using namespace std;


int arr[1000000] = { 0 }; //나무 N개의 길이 저장

int cut(int tree, int saw) {
	tree = tree - saw;

	if (tree < 0) return 0;
	else return tree;
}

//int get_tree(int )


int main() {
	int N, M;

	cin >> N >> M;

	int max = 0, min = 0;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];

		if (arr[i] > max) max = arr[i];

		if (arr[i] < min) min = arr[i];
	}

	int left = min, right = max; //나무들 중 최대 길이와 최소 길이 사이에서 값 찾기

	//saw>=M이면서 가장 큰 saw 값 찾기

	int max_saw = 0;

	while (left <= right) {
		int saw = (left + right) / 2; //saw는 자를 길이
		long long sum = 0;	//H에 따라 가져가는 나무 길이 저장

		for (int i = 0; i < N; i++) {
			sum += cut(arr[i], saw);
		}

		if (sum >= M) {
			max_saw = saw;
			left = saw + 1;
		}
		else right = saw - 1;
	}

	cout << max_saw;
}