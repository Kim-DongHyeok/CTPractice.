#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int N, M;
int card[500000], check[500000];

int lower(int arr[], int target) {
	int left = 0;
	int right = N - 1;
	int min_idx = N;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] >= target) {
			right = mid - 1;
			min_idx = min_idx < mid ? min_idx : mid;
		}
		else
			left = mid + 1;
	}

	return min_idx;
}

int upper(int arr[], int target) {
	int left = 0;
	int right = N - 1;
	int min_idx = N;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] > target) {
			right = mid - 1;
			min_idx = min_idx < mid ? min_idx : mid;
		}
		else
			left = mid + 1;
	}

	return min_idx;
}

int main() {

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> card[i];
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> check[i];
	}

	sort(card, card + N);

	for (int i = 0; i < M; i++) {
		check[i] = upper(card, check[i]) - lower(card, check[i]);
	}

	for (int i = 0; i < M; i++) {
		cout << check[i] << ' ';
	}

	return 0;
}