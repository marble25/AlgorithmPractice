#include <iostream>
int arr[1000001] = { 0 };
using namespace std;
int main() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << "0" << "\n";
		return 0;
	}
	for (int i = n; i >= 1; i--) {
		if (i % 2 == 0) {
			if (arr[i / 2] != 0) {
				arr[i / 2] = (arr[i / 2] > arr[i] + 1 ? arr[i] + 1 : arr[i / 2]);
			}
			else {
				arr[i / 2] = arr[i] + 1;
			}
		}
		if (i % 3 == 0) {
			if (arr[i / 3] != 0) {
				arr[i / 3] = (arr[i / 3] > arr[i] + 1 ? arr[i] + 1 : arr[i / 3]);
			}
			else {
				arr[i / 3] = arr[i] + 1;
			}
		}

		if (arr[i-1] != 0) {
			arr[i-1] = (arr[i-1] > arr[i] + 1 ? arr[i] + 1 : arr[i-1]);
		}
		else {
			arr[i-1] = arr[i] + 1;
		}
	}
	cout << arr[1] << "\n";
}