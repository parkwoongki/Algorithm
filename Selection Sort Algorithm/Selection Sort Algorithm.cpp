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
		int largest = theLargest(array, n - i); // ���� ū �� ã��
		swap(&array[largest], &array[n - i - 1]); // ���� ū ���� �� �ڿ������� �ִ´�.
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

	start = clock(); // ���� ����
	selectionSort(array, 10000);
	end = clock(); // ���� ����

	result = (double)(end - start);

	for (int i = 0; i < 10000; i++) {
		printf("%d, ", array[i]);
	}

	printf("�ɸ� �ð� : %lfms", result);

	return 0;
}