#include <stdio.h>

int arr[100];
int a = 0;

void loop(int n) {
    if (n < 0) return;
    loop(n - 1);

    if (arr[n] >= a) {
        a = arr[n];
        return;
    }
    else {
        return;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // Please write your code here.

    loop(n);

    printf("%d", a);


    return 0;
}
