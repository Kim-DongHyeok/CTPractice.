#include <iostream>

using namespace std;

int N;
int arr[100000];
int *arr_sort;

void merge(int left, int right)
{
	int mid = (left + right) / 2;

	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j]) 
			arr_sort[k++] = arr[i++]; 
		else
			arr_sort[k++] = arr[j++];
	}

	int tmp = i>mid ? j : i;
	
	while(k<=right) arr_sort[k++] = arr[tmp++];

	for (int i=left;i<=right;i++) arr[i] = arr_sort[i];
}

void merge_sort(int left,int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2; 
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merge(left, right);
	}
}




int main() {
    cin >>N;

    arr_sort = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    merge_sort(0, N-1);

    for(int i=0; i<N; i++) cout << arr[i] << " ";
    // Please write your code here.

    return 0;
}
