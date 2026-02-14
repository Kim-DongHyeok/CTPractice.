#include <iostream>
#include <deque>
#include <utility>

using namespace std;

bool visited[100001];

void bfs(int start, int K) {
    deque<pair<int, int>> dq;
    
    dq.push_back({start, 0});
    visited[start] = true;

    while (!dq.empty()) {
        int node = dq.front().first;
        int cnt = dq.front().second;
        dq.pop_front();

        if (node == K) {
            cout << cnt;
            return;
        }

        if (node * 2 <= 100000 && !visited[node * 2]) {
            visited[node * 2] = true;
            dq.push_front({node * 2, cnt});
        }

        if (node - 1 >= 0 && !visited[node - 1]) {
            visited[node - 1] = true;
            dq.push_back({node - 1, cnt + 1});
        }

        if (node + 1 <= 100000 && !visited[node + 1]) {
            visited[node + 1] = true;
            dq.push_back({node + 1, cnt + 1});
        }
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    bfs(N, K);
    return 0;
}