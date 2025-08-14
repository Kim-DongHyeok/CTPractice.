#include <iostream>
using namespace std;

int arr[129][129];
int white_count = 0;
int blue_count = 0;

void divide(int x, int y, int size) {
    int color = arr[x][y];
    bool same = true;

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (arr[i][j] != color) {
                same = false;
                break;
            }
        }
        if (!same) break;
    }

    if (same) {
        if (color == 0) white_count++;
        else blue_count++;
        return;
    }

    int half = size / 2;
    divide(x, y, half);               // 1사분면
    divide(x, y + half, half);        // 2사분면
    divide(x + half, y, half);        // 3사분면
    divide(x + half, y + half, half); // 4사분면
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    divide(0, 0, N);

    cout << white_count << "\n" << blue_count << "\n";
    return 0;
}
