#include <stdio.h>
#include <time.h>
#include <iostream>
#include <cstdlib>

void swap(int* n, int* m) {
	int tmp = *n;
	*n = *m;
	*m = tmp;
}

void bubbleSort(int array[], int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (array[j] > array[j + 1])
				swap(&array[j], &array[j + 1]);
		}
	}
}

void theTenThousand(int array[]) {
	std::srand(5323);
	for (int i = 0; i < 10000; ++i) {
		array[i] = std::rand();
	}
}

int main() {
	int array[10000];
	theTenThousand(array);

	time_t start, end;
	double result;

	start = clock(); // 측정 시작
	bubbleSort(array, 10000);
	end = clock(); // 측정 종료

	result = (double)(end - start);

	for (int i = 0; i < 10000; i++) {
		printf("%d, ", array[i]);
	}

	printf("걸린 시간 : %lfms", result);

	return 0;
}