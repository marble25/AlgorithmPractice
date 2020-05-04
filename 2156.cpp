#include <iostream>
using namespace std;
int max(int x, int y) {
	return (x > y ? x : y);
}
int main() {
	int n;
	int arr[10005];
	int check[10005][2];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	check[0][0] = arr[0];
	check[0][1] = 0;
	check[1][0] = arr[1];
	check[1][1] = arr[0] + arr[1];
	check[2][0] = arr[0] + arr[2];
	check[2][1] = arr[1] + arr[2];

	for (int i = 3; i < n; i++) {
		check[i][0] = max(max(check[i - 2][0], check[i - 2][1]), max(check[i - 3][0], check[i - 3][1])) + arr[i];
		check[i][1] = check[i - 1][0] + arr[i];
	}
	int max_val = -999;
	for (int i = 0; i < n; i++) {
		if (check[i][0] > max_val) {
			max_val = check[i][0];
		}
		if (check[i][1] > max_val) {
			max_val = check[i][1];
		}
	}
	cout << max_val;
}