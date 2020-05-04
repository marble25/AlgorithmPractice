#include <iostream>

using namespace std;
long long fac[15];

int main() {
	int n;

	cin >> n;
	fac[0] = 1;
	for (int i = 1; i <= 12; i++) {
		fac[i] = (fac[i - 1] * i);
	}

	cout << fac[n] << "\n";

}