#include <iostream>
using namespace std;
int main() {
	int T;
	int k, n;
	int table[15][15];
	for (int i = 0; i < 15; i++) {
		table[0][i] = i;
	}
	for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			int sum = 0;
			for (int k = 1; k <= j; k++) {
				sum += table[i - 1][k];
			}
			table[i][j] = sum;
		}
	}
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> k >> n;
		cout << table[k][n] << "\n";
	}
}