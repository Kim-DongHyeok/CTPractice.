#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int target_num = 0;

    for (int i = 0; i < 3; i++) {
        cin >> s;
        if (s[0] != 'F' && s[0] != 'B') {
            target_num = stoi(s) + (3 - i);
        }
    }

    if (target_num % 3 == 0 && target_num % 5 == 0) {
        cout << "FizzBuzz" << "\n";
    } else if (target_num % 3 == 0) {
        cout << "Fizz" << "\n";
    } else if (target_num % 5 == 0) {
        cout << "Buzz" << "\n";
    } else {
        cout << target_num << "\n";
    }

    return 0;
}