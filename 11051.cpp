#include <iostream>

#define p 10007LL
using namespace std;
long long fac[1005];

long long power(long long x, long long y) {
	long long ret = 1;
	while (y > 0) {
		if (y % 2 == 1) {
			ret *= x;
			ret %= p;
		}
		y /= 2;
		x *= x;
		x %= p;
	}
	return ret;
}
int main() {
	int n, k;

	cin >> n >> k;
	fac[0] = 1;
	for (int i = 1; i <= 1000; i++) {
		fac[i] = (fac[i - 1] * i) % p;
	}

	long long d1 = power(fac[k], p - 2);
	long long d2 = power(fac[n - k], p - 2);

	long long result = (fac[n] * d1) % p;
	result = (result * d2) % p;

	cout << result << "\n";

}