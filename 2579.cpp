#include <iostream>
using namespace std;
int max(int x, int y) {
	return (x < y ? y : x);
}
int main() {
	int n;
	int arr[300], result[300][2], count[300][2];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	if (n == 1) {
		cout << arr[0];
	}
	result[0][0] = arr[0];
	result[1][0] = arr[1];
	result[1][1] = arr[0] + arr[1];

	for (int i = 2; i < n; i++) {
		result[i][0] = max(result[i - 2][0], result[i - 2][1]) + arr[i];
		result[i][1] = result[i - 1][0] + arr[i];
	}
	cout << max(result[n - 1][0], result[n - 1][1]) << "\n";
}