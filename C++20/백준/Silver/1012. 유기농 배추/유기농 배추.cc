#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int arr[50][50] = { 0 };
bool visited[50][50] = { false };
int Count = 0;

//인접 정보 처리
//상하좌우 확인 후 graph에 추가
//bfs 알고리즘이지만 인접은 상하좌우만 해당함

void reset() {
	memset(arr, 0, sizeof(arr));
	memset(visited, 0, sizeof(visited));
	Count = 0;
}

void bfs(int x, int y) { //x 가로, y 세로
	queue<int> H, V;

	visited[y][x] = 1;

	H.push(x);
	V.push(y);

	while (!H.empty()) {
		int h = H.front();
		int v = V.front();
		
		H.pop();
		V.pop();

		if (h != 0) {//좌측 모서리 제외
			if (arr[v][h - 1] == 1 && visited[v][h-1] == false) {//좌측 인접 확인
				visited[v][h - 1] = true;
				H.push(h - 1);
				V.push(v);
			}
		}
		if (h != 49) {//우측 모서리 제외
			if (arr[v][h + 1] == 1 && visited[v][h + 1] == false) {//우측 인접 확인
				visited[v][h + 1] = true;
				H.push(h + 1);
				V.push(v);
			}
		}
		if (v != 0) {
			if (arr[v-1][h] == 1 && visited[v-1][h] == false) {
				visited[v-1][h] = true;
				H.push(h);
				V.push(v-1);
			}
		}
		if (v != 49) {
			if (arr[v+1][h] == 1 && visited[v+1][h] == false) {
				visited[v+1][h] = true;
				H.push(h);
				V.push(v+1);
			}
		}
	}

	Count++;
}

int main() {
	int T;
	cin >> T;

	for (int re = 0; re < T; re++) {
		int M, N, K;

		cin >> M >> N >> K;


		for (int i = 0; i < K; i++) {
			int X, Y;
			cin >> X >> Y;

			arr[Y][X] = 1;
		}

		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 50; j++) {
				if (arr[i][j] == 1 && visited[i][j] == false) bfs(j, i);
				else continue;
			}
		}

		cout << Count << "\n";

		reset();

	}
}