#include <cstdio>
int map[2300][2300];
int a, b, c;
using namespace std;
void count(int x, int y, int adder) {
	if (map[x][y] == -1) {
		a+= adder;
	}
	else if (map[x][y] == 0) {
		b+= adder;
	}
	else {
		c+= adder;
	}
}
int check(int left_x, int left_y, int n) {
	int x = map[left_x][left_y];
	bool flag = true;

	if (n == 1) {
		count(left_x, left_y, 1);
		return map[left_x][left_y];
	}
	for (int i = left_x; i < left_x + n; i+=n/3) {
		for (int j = left_y; j < left_y + n; j+=n/3) {
			if (x != check(i, j, n/3)) {
				flag = false;
			}
		}
	}

	if (flag) {
		count(left_x, left_y, -8);
		return x;
	}
	return -2;
	
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	a = b = c = 0;
	check(0, 0, n);
	printf("%d %d %d", a, b, c);
}