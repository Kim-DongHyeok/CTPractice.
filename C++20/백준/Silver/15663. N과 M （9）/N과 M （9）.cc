#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int arr[8];
int result[8];
bool used[8] = { false };

void pr() {
    for (int i = 0; i < M; i++) {
        cout << result[i] << " ";
    }
    cout << '\n';
}

void back(int x) {
    if (x == M) {
        pr();
        return;
    }

    int last_used = -1; 
    for (int i = 0; i < N; i++) {
        if (!used[i] && arr[i] != last_used) {
            used[i] = true;
            result[x] = arr[i];
            last_used = arr[i]; 
            back(x + 1);
            used[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> arr[i];

    sort(arr, arr + N); 

    back(0);
    return 0;
}