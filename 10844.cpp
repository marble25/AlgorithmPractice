#include <iostream>
using namespace std;
long long arr[101][10];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < 10; i++) {
		arr[n][i] = 1;
	}
	for (int i = n - 1; i >= 1; i--) {
		arr[i][0] = arr[i + 1][1];
		arr[i][9] = arr[i + 1][8];
		for (int j = 1; j < 9; j++) {
			arr[i][j] = (arr[i + 1][j - 1] + arr[i + 1][j + 1]) % 1000000000;
		}
	}
	long long result = 0;
	for (int i = 1; i < 10; i++) {
		result += arr[1][i];
		result %= 1000000000;
	}
	cout << result << "\n";
}