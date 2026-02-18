#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int sum = 0;
    int target_idx = 0;

    for (int i = 0; i < 13; i++) {
        if (s[i] == '*') {
            target_idx = i;
            continue;
        }

        int num = s[i] - '0';
        if (i % 2 == 0) sum += num * 1;
        else sum += num * 3;
    }

    for (int i = 0; i <= 9; i++) {
        int temp_sum = sum;
        if (target_idx % 2 == 0) temp_sum += i * 1;
        else temp_sum += i * 3;

        if (temp_sum % 10 == 0) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}