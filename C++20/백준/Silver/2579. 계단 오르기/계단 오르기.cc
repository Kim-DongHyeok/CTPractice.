#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> s(n + 1, 0);
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    dp[1] = s[1];
    if (n >= 2) dp[2] = s[1] + s[2];
    if (n >= 3) {
        for (int i = 3; i <= n; i++) {
            dp[i] = max(dp[i - 2] + s[i], dp[i - 3] + s[i - 1] + s[i]);
        }
    }

    cout << dp[n] << endl;

    return 0;
}