#include <stdio.h>

int min(int, int, int);

void main(void) {
	printf("가장 작은 수 : %d", min(1, 2, 3));

	getchar();
	getchar();
}

int min(int a, int b, int c) {
	int k = 0;

	if (a < b) {
		if (a < c) k = a;
		else k = c;
	}
	else {
		if (b < c) k = b;
		else k = c;
	}

	return k;
}