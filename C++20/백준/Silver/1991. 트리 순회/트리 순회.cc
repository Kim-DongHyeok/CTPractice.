#include <iostream>
#include <vector>

using namespace std;

struct Node {
    char left;
    char right;
};

Node tree[26];
int N;

void preOrder(char node) {
    if (node == '.') return;
    cout << node;
    preOrder(tree[node - 'A'].left);
    preOrder(tree[node - 'A'].right);
}

void inOrder(char node) {
    if (node == '.') return;
    inOrder(tree[node - 'A'].left);
    cout << node;
    inOrder(tree[node - 'A'].right);
}

void postOrder(char node) {
    if (node == '.') return;
    postOrder(tree[node - 'A'].left);
    postOrder(tree[node - 'A'].right);
    cout << node;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        char root, left, right;
        cin >> root >> left >> right;
        tree[root - 'A'].left = left;
        tree[root - 'A'].right = right;
    }

    preOrder('A');
    cout << "\n";
    inOrder('A');
    cout << "\n";
    postOrder('A');
    cout << "\n";

    return 0;
}