#include <iostream>

using namespace std;

int n;
int arr[100000];

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort(int arr[], int start, int end) {
    if (start >= end) return;

    int pivot = arr[(start+end)/2];
    int left = start + 1;
    int right = end;

    while (left <= right) {
        while (left <= end && arr[left] < pivot) left++;
        while (right > start && arr[right] > pivot) right--;

        if (left < right) {
            swap(&arr[left], &arr[right]);
        }
        else swap(&arr[right], &arr[start]);
    }


    sort(arr, start, right - 1);
    sort(arr, right + 1, end);
}


int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, 0, n-1);


    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    

    return 0;
}

