#include <iostream>
using namespace std;
int min(int a, int b) {
	return (a > b ? b : a);
}
int main() {
	int arr[1000][3];
	int result[1000][3];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		result[0][i] = arr[0][i];
	}
	for (int i = 1; i < n; i++) {
		result[i][0] = arr[i][0] + min(result[i-1][1], result[i-1][2]);
		result[i][1] = arr[i][1] + min(result[i-1][0], result[i-1][2]);
		result[i][2] = arr[i][2] + min(result[i-1][1], result[i-1][0]);
	}
	
	cout << min(min(result[n - 1][0], result[n - 1][1]), result[n - 1][2]) << "\n";
}