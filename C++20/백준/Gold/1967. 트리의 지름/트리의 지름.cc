#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<pair<int, int>> tree[10001];
bool visited[10001];
int maxDist = 0;
int farNode = 0;

void dfs(int now, int dist) {
    visited[now] = true;

    if (dist > maxDist) {
        maxDist = dist;
        farNode = now;
    }

    for (int i = 0; i < tree[now].size(); i++) {
        int nextNode = tree[now][i].first;
        int nextDist = tree[now][i].second;
        
        if (!visited[nextNode]) {
            dfs(nextNode, dist + nextDist);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if (n == 1) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        tree[u].push_back({ v, w });
        tree[v].push_back({ u, w });
    }

    memset(visited, false, sizeof(visited));
    dfs(1, 0);

    memset(visited, false, sizeof(visited));
    maxDist = 0;
    dfs(farNode, 0);

    cout << maxDist;

    return 0;
}