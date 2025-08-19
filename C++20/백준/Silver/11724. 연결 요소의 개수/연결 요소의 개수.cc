#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> graph[1000];
bool visited[1000] = { false };
queue<int> q;

int CC = 0;

void bfs(int start) {
	visited[start] = true;
	q.push(start);
	
	while (!q.empty()) {
		int first = q.front();
		q.pop();

		for (int i = 0; i < graph[first].size(); i++) {
			if (visited[graph[first][i]] == false) {
				q.push(graph[first][i]);
				visited[graph[first][i]] = true;
			}
		}
	}

	
}


int main(){
	int N, M;

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v;

		cin >> u >> v;

		graph[u-1].push_back(v-1);
		graph[v-1].push_back(u-1);
	}

	for (int i = 0; i < N; i++) {
		if (visited[i] == false) {
			bfs(i);
			CC++;
		}
	}

	cout << CC;
}