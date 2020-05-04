#include <iostream>
using namespace std;
int input[505];
int arr[505][505];
int re[505][505];
int main() {
	
	int T;
	int n;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> input[j];
		}
		int sum = 0;
		
		for (int j = 0; j < n; j++) {
			arr[j][j] = input[j];
			re[j][j] = 0;
		}
		
		for (int j = n - 2; j >= 0; j--) {
			for (int k = j + 1; k < n; k++) {
				int min = 2100000000;
				for (int l = j; l < k; l++) {
					if (arr[j][l] + arr[l + 1][k] + re[j][l] + re[l + 1][k] < min) {
						min = arr[j][l] + arr[l + 1][k] + re[j][l] + re[l + 1][k];
						arr[j][k] = arr[j][l] + arr[l + 1][k];
					}
				}
				re[j][k] = min;
			}
		}
		cout << re[0][n - 1] << "\n";

	}
}