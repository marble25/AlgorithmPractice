#include <iostream>
using namespace std;
char arr[3072][6144];
void print(int n, int x, int y) {
	if (n == 3) {
		arr[x][y] = '*';
		arr[x + 1][y - 1] = '*';
		arr[x + 1][y + 1] = '*';
		for (int i = -2; i <= 2; i++) {
			arr[x + 2][y + i] = '*';
		}
		return;
	}
	print(n / 2, x, y);
	print(n / 2, x + n / 2, y + n / 2);
	print(n / 2, x + n / 2, y - n / 2);
}
int main() {
	int x;
	cin >> x;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x * 2; j++) {
			arr[i][j] = ' ';
		}
	}
	print(x, 0, x - 1);
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x * 2; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
		
	}
}