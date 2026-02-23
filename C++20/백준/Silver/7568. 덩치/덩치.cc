#include <iostream>
#include <vector>

using namespace std;

struct Person {
    int weight;
    int height;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<Person> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].weight >> v[i].height;
    }

    for (int i = 0; i < N; i++) {
        int rank = 1;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (v[i].weight < v[j].weight && v[i].height < v[j].height) {
                rank++;
            }
        }
        cout << rank << " ";
    }

    return 0;
}