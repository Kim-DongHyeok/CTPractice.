#include <iostream>
#include <string>
#include <unordered_map> 

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    unordered_map<string, string> dict;

    string site, password;
    for (int i = 0; i < a; i++) {
        cin >> site >> password;
        dict[site] = password; 
    }

    for (int i = 0; i < b; i++) {
        cin >> site;
        cout << dict[site] << "\n"; 
    }

    return 0;
}