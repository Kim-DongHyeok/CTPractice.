#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        queue<pair<int, int>> q;
        priority_queue<int> pq;

        for (int i = 0; i < N; i++) {
            int priority;
            cin >> priority;
            q.push({i, priority});
            pq.push(priority);
        }

        int count = 0;
        while (!q.empty()) {
            int index = q.front().first;
            int value = q.front().second;
            q.pop();

            if (pq.top() == value) {
                count++;
                pq.pop();
                if (index == M) {
                    cout << count << "\n";
                    break;
                }
            } else {
                q.push({index, value});
            }
        }
    }

    return 0;
}