#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    int dp[31][31] = {0};

    for (int i = 0; i <= 30; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            if (i == j) dp[i][j] = 1;
            else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    while (T--) {
        int N, M;
        cin >> N >> M;
        cout << dp[M][N] << "\n";
    }

    return 0;
}