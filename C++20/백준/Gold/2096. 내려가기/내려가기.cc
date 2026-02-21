#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int max_dp[3], min_dp[3];
    int next_max[3], next_min[3];

    for (int i = 0; i < 3; i++) {
        int num;
        cin >> num;
        max_dp[i] = min_dp[i] = num;
    }

    for (int i = 1; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        next_max[0] = a + max(max_dp[0], max_dp[1]);
        next_max[1] = b + max({max_dp[0], max_dp[1], max_dp[2]});
        next_max[2] = c + max(max_dp[1], max_dp[2]);

        next_min[0] = a + min(min_dp[0], min_dp[1]);
        next_min[1] = b + min({min_dp[0], min_dp[1], min_dp[2]});
        next_min[2] = c + min(min_dp[1], min_dp[2]);

        for (int j = 0; j < 3; j++) {
            max_dp[j] = next_max[j];
            min_dp[j] = next_min[j];
        }
    }

    cout << max({max_dp[0], max_dp[1], max_dp[2]}) << " " << min({min_dp[0], min_dp[1], min_dp[2]}) << "\n";

    return 0;
}