#include <stdio.h>
 main() {
	int arr[3];
	int box;
	int i, j;
	scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
	for(i = 0; i < 3; i++){
		for (j = 0; j < 2; j++) {
			if (arr[j] <= arr[j + 1]) {
				box = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = box;
			}
}
	}
	printf("%d", arr[1]);
}