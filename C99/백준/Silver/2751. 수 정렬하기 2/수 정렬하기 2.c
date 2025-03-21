#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    int* leftArr = (int*)malloc(leftSize * sizeof(int));
    int* rightArr = (int*)malloc(rightSize * sizeof(int));

    for (int i = 0; i < leftSize; i++) leftArr[i] = arr[left + i];
    for (int i = 0; i < rightSize; i++) rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) arr[k++] = leftArr[i++];
        else arr[k++] = rightArr[j++];
    }

    while (i < leftSize) arr[k++] = leftArr[i++];
    while (j < rightSize) arr[k++] = rightArr[j++];

    free(leftArr);
    free(rightArr);
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    int N;
    scanf("%d", &N);
    int* nums = (int*)malloc(N * sizeof(int));
   

    for (int i = 0; i < N; i++) {
        scanf("%d", &nums[i]);
    }

    mergeSort(nums, 0, N - 1);

    for (int i = 0; i < N; i++) {
        printf("%d\n", nums[i]);
    }

    free(nums);
    return 0;
}