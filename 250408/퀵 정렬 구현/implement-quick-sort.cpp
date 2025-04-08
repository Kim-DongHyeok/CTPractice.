#include <iostream>
#include <cstdlib>
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

    int pivot = arr[(start + end) / 2];
    int left = start;
    int right = end;

    while (left <= right) {
        while (arr[left] < pivot) left++;
        while (arr[right] > pivot) right--;

        if (left <= right) {
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
    }

    sort(arr, start, right);
    sort(arr, left, end);
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

