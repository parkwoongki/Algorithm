#include <stdio.h>
#include <time.h>
#include <iostream>
#include <cstdlib>

int theLargest(int array[], int last) {
	int largest = 0;

	for (int i = 1; i < last; ++i) {
		if (array[largest] < array[i])
			largest = i;
	}

	return largest;
}

void swap(int* n, int* m) {
	int tmp = *n;
	*n = *m;
	*m = tmp;
}

void selectionSort(int array[], int n) {
	for (int i = 0; i < n; i++) {
		int largest = theLargest(array, n - i); // 가장 큰 수 찾기
		swap(&array[largest], &array[n - i - 1]); // 가장 큰 수를 맨 뒤에서부터 넣는다.
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
	selectionSort(array, 10000);
	end = clock(); // 측정 종료

	result = (double)(end - start);

	for (int i = 0; i < 10000; i++) {
		printf("%d, ", array[i]);
	}

	printf("걸린 시간 : %lfms", result);

	return 0;
}