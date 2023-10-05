#include <stdio.h>

main() {
	int arr[8];
	int a = 0;
	int b = 0;

	for (int i = 0; i < 8; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < 8; i++) {
		if (arr[i + 1] - arr[i] == 1)
			a++;
		else if (arr[i] - arr[i + 1] == 1)
			b++;
	}
	if (a == 7)
		printf("ascending");
	else if (b == 7)
		printf("descending");
	else
		printf("mixed");
}