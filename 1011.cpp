#include <iostream>
using namespace std;
long long arr[3000000];

int main() {
	int T;

	arr[0] = 0;
	int count = 0;
	for (int i = 1; i < 3000000; i++) {
		if (i % 2 != 0) {
			count++;
		}
		arr[i] = arr[i - 1] + count;
	}

	cin >> T;
	for (int i = 0; i < T; i++) {
		int x, y, dis;
		cin >> x >> y;
		dis = y - x;
		for (int j = 0; j < 3000000; j++) {
			if (arr[j] >= dis) {
				cout << j << "\n";
				break;
			}
		}
	}
}