#include <iostream>
using namespace std;
int main() {
	int m;
	int arr[4];
	for (int i = 1; i <= 3; i++) {
		arr[i] = i;
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		int temp;
		temp = arr[x];
		arr[x] = arr[y];
		arr[y] = temp;
	}

	for (int i = 1; i <= 3; i++) {
		if (arr[i] == 1) {
			cout << i;
			break;
		}
	}
}