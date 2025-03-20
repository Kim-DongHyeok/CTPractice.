#include <stdio.h>

int main() {
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	int n = a * b * c;
	int m = 0, i=0;
	int arr[10] = { 0 };

	while (n > 0) {
		arr[n % 10]++;
		
		n = n / 10;
	}

	while (i < 10) {
		printf("%d\n", arr[i]);
		i++;
	}
}