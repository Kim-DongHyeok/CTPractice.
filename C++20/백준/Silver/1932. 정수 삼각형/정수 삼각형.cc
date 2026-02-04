#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

vector<int> tri[500];
vector<int> res[500];

int main() {
	int n, input;

	cin >> n;

    if(n==1){
        cin >> input;
        cout << input;
        return 0;
    }

	for (int i = 1; i < n+1; i++) {
		for (int j = 0; j < i; j++) {
			cin >> input;
			tri[i].push_back(input);
		}
	}

	res[2].push_back(tri[1][0] + tri[2][0]);
	res[2].push_back(tri[1][0] + tri[2][1]);

	int th = 0;


	for (int i = 3; i < n+1; i++) {
		for (int j = 0; j < i; j++) {
			if (j == 0) {
				res[i].push_back(tri[i][j]+res[i-1][j]);
				continue;
			}
			else if (j == i-1) {
				res[i].push_back(tri[i][j]+res[i-1][j-1]);
				continue;
			}

			th = max(res[i - 1][j - 1], res[i - 1][j]);
			res[i].push_back(th + tri[i][j]);

		}
	}

	int largest = res[n][0];

	for (int i = 1; i < n; i++) {
		largest = max(largest, res[n][i]);
	}

	cout << largest;
}