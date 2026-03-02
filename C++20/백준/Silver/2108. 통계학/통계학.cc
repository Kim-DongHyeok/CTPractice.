#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> v(N);
    int count[8001] = {0}; 
    double sum = 0;

    for (int i = 0; i < N; i++) {
        cin >> v[i];
        sum += v[i];
        count[v[i] + 4000]++; 
    }

    sort(v.begin(), v.end());

    // 1. 산평
    int avg = round(sum / N);
    if (avg == -0) avg = 0;
    cout << avg << "\n";

    // 2. 중앙
    cout << v[N / 2] << "\n";

    // 3. 최빈
    int max_freq = 0;
    for (int i = 0; i < 8001; i++) {
        if (count[i] > max_freq) max_freq = count[i];
    }

    vector<int> modes;
    for (int i = 0; i < 8001; i++) {
        if (count[i] == max_freq) {
            modes.push_back(i - 4000);
        }
    }

    if (modes.size() > 1) {
        sort(modes.begin(), modes.end());
        cout << modes[1] << "\n"; // 둘째최소
    } else {
        cout << modes[0] << "\n";
    }

    
    cout << v[N - 1] - v[0] << "\n";

    return 0;
}