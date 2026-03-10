#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    string pattern;
    cin >> pattern;

    for (int i = 1; i < N; i++) {
        string next;
        cin >> next;
        for (int j = 0; j < pattern.length(); j++) {
            if (pattern[j] != next[j]) {
                pattern[j] = '?';
            }
        }
    }

    cout << pattern << "\n";

    return 0;
}