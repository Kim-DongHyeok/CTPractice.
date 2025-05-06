#include <iostream>
#include <queue>

using namespace std;

int N, K;

int main() {
    cin >> N >> K;

    queue<int> p;

    for (int i = 1; i <= N; i++) {
        p.push(i);
    }

    while (p.size() != 1) {
        for (int i = 0; i < K-1; i++) {
            p.push(p.front());
            p.pop();
        }

        cout << p.front() << ' ';
        p.pop();
    }

    cout << p.front();

    return 0;
}


//1=ture, 0=false