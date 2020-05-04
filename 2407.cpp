#include <iostream>

using namespace std;
long long fac1[105][105], fac2[105][105];

int main() {
	int n, k;

	cin >> n >> k;

	fac1[0][0] = 0;
	fac2[0][0] = 1;

	for (int i = 1; i <= 100; i++) {
		fac2[i][0] = 1;
		fac1[i][0] = 0;
		for (int j = 1; j <= i; j++) {
			fac2[i][j] = fac2[i - 1][j - 1] + fac2[i - 1][j];
			fac1[i][j] = fac1[i - 1][j - 1] + fac1[i - 1][j];
			fac1[i][j] += fac2[i][j] / 10000000000000LL;
			fac2[i][j] = fac2[i][j] % 10000000000000LL;
		}
	}

	if (fac1[n][k] != 0) {
		cout << fac1[n][k];
		cout.fill('0');
		cout.width(13);
	}
	cout << fac2[n][k] << "\n";

}