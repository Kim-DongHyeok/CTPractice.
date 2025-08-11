#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> minHeap; // 최소 힙

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        if (x > 0) {
            minHeap.push(x);
        } else { // x == 0
            if (minHeap.empty()) {
                cout << 0 << '\n';
            } else {
                cout << minHeap.top() << '\n';
                minHeap.pop();
            }
        }
    }
    return 0;
}
