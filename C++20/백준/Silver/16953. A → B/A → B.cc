#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B;
    cin >> A >> B;

    int count = 1;

    while (B > A) {
        if (B % 2 == 0) {
            B /= 2;
        } else if (B % 10 == 1) {
            B /= 10;
        } else {
            break;
        }
        count++;
    }

    if (B == A) {
        cout << count << "\n";
    } else {
        cout << -1 << "\n";
    }

    return 0;
}