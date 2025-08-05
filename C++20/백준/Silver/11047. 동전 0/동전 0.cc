#include <iostream>
using namespace std;

int N, K;
int coins[10];

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }

    int count = 0;

    for (int i = N - 1; i >= 0; i--) { // 큰 동전부터
        if (coins[i] <= K) {
            count += K / coins[i];   // 몫만큼 사용
            K %= coins[i];           // 나머지 금액 갱신
        }
    }

    cout << count << '\n';
    return 0;
}
