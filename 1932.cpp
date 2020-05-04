#include <iostream>
using namespace std;
int arr[500][500], re[500][500];
int max(int a, int b) {
	return (a > b ? a : b);
}
int main() {
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
		}
	}
	re[0][0] = arr[0][0];
	for (int i = 1; i < n; i++) {
		re[i][0] = re[i - 1][0] + arr[i][0];
		for (int j = 1; j < i; j++) {
			re[i][j] = max(re[i - 1][j - 1], re[i - 1][j]) + arr[i][j];
		}
		re[i][i] = re[i - 1][i - 1] + arr[i][i];
	}
	int maxValue = -1;
	for (int i = 0; i < n; i++) {
		if (re[n - 1][i] > maxValue) {
			maxValue = re[n - 1][i];
		}
	}

	cout << maxValue << "\n";
}