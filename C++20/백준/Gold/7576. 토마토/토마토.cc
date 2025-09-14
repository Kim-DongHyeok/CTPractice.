#include <iostream>
#include <queue>
using namespace std;

int arr[1000][1000];
queue<pair<int, int>> q;
bool visited[1000][1000] = { false };

void bfs(int N, int M) {
    int dirY[4] = { -1, 1, 0, 0 };
    int dirX[4] = { 0, 0, -1, 1 };

    while (!q.empty()) {
        auto now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = now.first + dirY[i];
            int nx = now.second + dirX[i];

            if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
                if (!visited[ny][nx] && arr[ny][nx] == 0) {
                    visited[ny][nx] = true;
                    arr[ny][nx] = arr[now.first][now.second] + 1; // 날짜 기록
                    q.push({ny, nx});
                }
            }
        }
    }
}

int main() {
    int N, M;
    cin >> M >> N; // M: 가로, N: 세로

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    bfs(N, M);

    int day = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0) { // 아직 안 익은 게 있으면
                cout << -1;
                return 0;
            }
            day = max(day, arr[i][j]);
        }
    }

    cout << day - 1; 
}