#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        int min_val = 4; 
        for (int j = 1; j * j <= i; j++) {
            min_val = min(min_val, dp[i - j * j]);
        }
        dp[i] = min_val + 1;
    }

    cout << dp[n] << "\n";

    return 0;
}