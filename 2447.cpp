#include <iostream>
using namespace std;
char re[7000][7000];
void set(int x, int y, int size) {
	int next = size / 3;
	for (int i = x; i < x + size; i += next) {
		for (int j = y; j < y + size; j += next) {
			if (i == x + next && j == y + next) {
				continue;
			}
			if (next == 1) {
				re[i][j] = '*';
				continue;
			}
			set(i, j, next);
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			re[i][j] = ' ';
		}
		re[i][n] = '\0';
	}
	if (n == 1) {
		cout << "*\n";
		return 0;
	}

	set(0, 0, n);

	for (int i = 0; i < n; i++) {
		cout << re[i] << "\n";
	}
}