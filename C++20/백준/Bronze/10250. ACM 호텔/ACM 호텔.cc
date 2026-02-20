#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int H, W, N;
        cin >> H >> W >> N;

        int floor = N % H;
        int room = (N / H) + 1;

        if (floor == 0) {
            floor = H;
            room -= 1;
        }

        cout << floor;
        if (room < 10) cout << "0";
        cout << room << endl;
    }

    return 0;
}