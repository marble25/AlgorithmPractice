#include <iostream>
using namespace std;
bool arr[1000001];
int main() {
	for (int i = 0; i < 1000001; i++) {
		arr[i] = false;
	}
	arr[1] = true;
	for (long long i = 2; i < 1000001; i++) {
		if (arr[i] == false) {
			for (long long j = 2; i*j < 1000001; j++) {
				arr[i*j] = true;
			}
		}
	}
	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		int count = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (arr[i] == false) {
				count++;
			}
		}
		cout << count << "\n";
	}
}