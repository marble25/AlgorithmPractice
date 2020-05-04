#include <iostream>

using namespace std;
long long fac[15];

int main() {
	int n, k;

	cin >> n >> k;
	fac[0] = 1;
	for (int i = 1; i <= 10; i++) {
		fac[i] = (fac[i - 1] * i);
	}

	long long d1 = fac[k];
	long long d2 = fac[n - k];

	long long result = (fac[n] / d1);
	result = (result / d2);

	cout << result << "\n";

}