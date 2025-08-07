#include <iostream>
#include <vector>

using namespace std;


int main() {
    
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

	int N, M, first, last;

	cin >> N >> M;

	int arr[100000] = { 0 };
	int dp[100000];

	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		arr[i]=A;
	}

	dp[0]=arr[0];
	dp[1]=dp[0] + arr[1];

	for (int i = 2; i < N; i++) {
		dp[i]=dp[i - 1] + arr[i];
	}

	for (int i = 0; i < M; i++) {
		cin >> first >> last;

		first -= 1;
		last -= 1;

		if (first == 0) {
			cout << dp[last] << "\n";
       

		}
		else{
			cout << dp[last] - dp[first - 1] << "\n";

        }
    }


}
