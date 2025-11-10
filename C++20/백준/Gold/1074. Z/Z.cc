#include <iostream>
#include <cmath>

using namespace std;

int r, c;

//사분면 체크
int check(int n) {//n은 행렬 길이
	if (r < n / 2 && c < n / 2) {
		return 1;
	}
	else if (r > n / 2 && c < n / 2) {
		return 3;
	}
	else if (r < n / 2 && c > n / 2) {
		return 2;
	}
	else if (r > n / 2 && c > n / 2) {
		return 4;
	}
}

//사분면에 따른 count 추가값
int pluscount(int locate, int n) {//locate=사분면, n은 행렬 길이
	n = n / 2;
	if (locate == 1) {
		return 0;
	}
	else if (locate == 2) {
		return n * n;
	}
	else if (locate == 3) {
		return n * n * 2;
	}
	else if (locate == 4) {
		return n * n * 3;
	}
}

//사분면에 따른 좌표값 조정
int renew(int locate, int n) {//n은 한 변의 길이
	if (locate == 1) {
		return 0;
	}
	else if (locate == 2) {
		c = c - n / 2;
		return 0;
	}
	else if (locate == 3) {
		r = r - n / 2;
		return 0;
	}
	else if (locate == 4) {
		c = c - n / 2;
		r = r - n / 2;
		return 0;
	}
}

int main() {
	int N, count=0;

	cin >> N >> r >> c;

	for (int Num = pow(2, N); Num > 2; Num = Num/ 2) {
		int locate = check(Num); //현재 좌표의 사분면 위치 체크
		count+=pluscount(locate, Num); //사분면 위치에 따라 추가값 계산
		renew(locate, Num);
	}

	if (r == 0 && c == 0) count += 0;
	else if (r == 0 && c == 1) count += 1;
	else if (r == 1 && c == 0) count += 2;
	else if (r == 1 && c == 1) count += 3;//2x2 행렬에서 마지막 순서값 처리

	cout << count;
}