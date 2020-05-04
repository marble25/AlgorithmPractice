#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<long long>> matrix;
const long long mod = 1000000007LL;
matrix operator * (const matrix &a, const matrix &b) {
	int n = a.size();
	matrix c(n, vector<long long>(n));
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			for (int k = 0; k<n; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
			c[i][j] %= mod;
		}
	}
	return c;
}
long long gcd(long long x, long long y) {
	return (y == 0 ? x : gcd(y, x%y));
}
int main() {
	long long n, m;

	cin >> n >> m;

	long long g = gcd(n, m);

	if (g <= 1) {
		cout << 1 << '\n';
		return 0;
	}

	matrix ans = { { 1, 0 },{ 0, 1 } };
	matrix a = { { 1, 1 },{ 1, 0 } };

	while (g > 0) {
		if (g % 2 == 1) {
			ans = ans * a;
		}
		a = a * a;
		g /= 2;
	}

	cout << ans[0][1] << '\n';

	return 0;
}