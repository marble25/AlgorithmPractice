#include <iostream>
using namespace std;
bool arr[10001];
int main() {
	for (int i = 0; i < 10001; i++) {
		arr[i] = false;
	}
	arr[1] = true;
	for (int i = 2; i < 10001; i++) {
		if (arr[i] == false) {
			for (int j = 2; i*j < 10001; j++) {
				arr[i*j] = true;
			}
		}
	}

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int x = n / 2;
		while (x >= 1) {
			if (arr[x] == false && arr[n - x] == false) {
				cout << x << " " << n - x << "\n";
				break;
			}
			x--;
		}
	}
}