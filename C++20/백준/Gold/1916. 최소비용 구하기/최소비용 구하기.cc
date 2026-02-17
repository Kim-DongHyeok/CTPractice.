#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> node[20001];
int dis[20001];
const int INF = 1073741823;

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dis[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int now_dis = pq.top().first;
        int now_node = pq.top().second;
        pq.pop();

        if (dis[now_node] < now_dis) continue;

        int range = node[now_node].size();
        for (int i = 0; i < range; i++) {
            int connected_node = node[now_node][i].first;
            int weight = node[now_node][i].second;

            if (dis[connected_node] > now_dis + weight) {
                dis[connected_node] = now_dis + weight;
                pq.push(make_pair(dis[connected_node], connected_node));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E, start, end;
    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        node[u].push_back(make_pair(v, w));
    }

    fill(dis, dis + 20001, INF);

    cin >> start >> end;
    dijkstra(start);

    cout << dis[end];

    return 0;
}