#include <iostream>

using namespace std;

int n;
int arr[10];

//int a = 0;



int gcd(int a, int b) {
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int min(int p) {
    if (p==1) {
        return lcm(arr[p], arr[p-1]);
    }
    return lcm(arr[p], min(p-1));

}



int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (n == 1) {
        cout << arr[0];
    }
    else {
        cout << min(n - 1);
    }



    return 0;
}
