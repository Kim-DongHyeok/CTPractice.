#include <iostream>
#include <vector>

using namespace std;


int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n;

	int dp[1000];

	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 3;

	for (int i = 3; i < 1000; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2])%10007;
	}

	cout << dp[n - 1] % 10007;
}
