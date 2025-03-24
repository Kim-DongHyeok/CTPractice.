#include <stdio.h>


int main() {
	int arr[10001] = { 0 };

	int N, tmp;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &tmp);
		arr[tmp]++;
	}

	for (int i = 1; i <= 10000; i++) {
		if (arr[i] != 0) {
			for (int j = 0; j < arr[i]; j++) {
				printf("%d\n", i);
			}
		}
		else
			continue;
	}
}