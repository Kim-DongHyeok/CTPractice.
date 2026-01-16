#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr;
int input[8];
bool check[8] = { false };

//int check(int depth, int now);

void backtrack(int before, int depth) {
    if (depth == M) {
        for (int num : arr) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < N; i++) {
        //if (check(i, depth) == 0) continue;
        if (check[i] == true) continue;

        arr.push_back(input[i]);
        check[i] = true;

        backtrack(i, depth + 1);

        arr.pop_back(); 
        check[i] = false;
    }
}

/*int check(int depth, int now) {
    for (int i = 0; i < depth; i++) {
        if (arr[now] == arr[i]) return 0;
    }

    return 1;
}*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    int a;

    for (int i = 0; i < N; i++) {
        cin >> a;
        input[i] = a;
    }

    sort(input, input+N);

    backtrack(9, 0);


    return 0;
}