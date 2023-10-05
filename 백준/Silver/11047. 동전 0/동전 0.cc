#include <stdio.h>

int main() {
	int N;
	int A[10];
	int B[10] = { 0, };
	int K;
	int count = 0;

	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	for (int i = N - 1; i >= 0; i--) {
		B[i] = K / A[i];
		K %= A[i];
		count += B[i];
	}
	printf("%d", count);
}