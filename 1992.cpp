#include <cstdio>
int n;
int current;
char re[100000];
char arr[100][100];
using namespace std;
void func(int x, int y, int size) {
	if (size == 1) {
		re[current++] = arr[x][y];
		return;
	}
	int tmp = arr[x][y];
	bool status = false;
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (tmp != arr[i][j]) {
				status = true;
				break;
			}
		}
		if (status) {
			break;
		}
	}

	if (!status) {
		re[current++] = tmp;
	}
	else {
		re[current++] = '(';
		func(x, y, size / 2);
		func(x, y + size / 2, size / 2);
		func(x + size / 2, y, size / 2);
		func(x + size / 2, y + size / 2, size / 2);
		re[current++] = ')';
	}
}
int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", &arr[i]);
	}
	func(0, 0, n);
	printf("%s\n", re);
}