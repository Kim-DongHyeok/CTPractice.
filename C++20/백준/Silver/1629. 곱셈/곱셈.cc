#include <iostream>
using namespace std;

typedef long long ll;

ll power(ll a, ll b, ll c) {
    if (b == 0) return 1;
    if (b == 1) return a % c;

    
    ll half = power(a, b / 2, c);
    ll res = (half * half) % c; 
    if (b % 2 != 0) {
        res = (res * a) % c;
    }
    return res;
}

int main() {
    ll A, B, C;
    cin >> A >> B >> C;
    cout << power(A, B, C) << endl;
    return 0;
}