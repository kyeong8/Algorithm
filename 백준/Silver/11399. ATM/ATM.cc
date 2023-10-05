#include <stdio.h>
#include <stdlib.h>


int main() {

	int n;
	int temp;
	int sum = 0;

	scanf("%d", &n);

	int* ptr = (int *) malloc(sizeof(int) * n);
	 
	for (int i = 0; i < n; i++) {
		scanf("%d", &ptr[i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {

			if (ptr[j] >= ptr[j + 1]) {
				temp = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = temp;

			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			sum += ptr[j];
		}

	}

	printf("%d", sum);

}