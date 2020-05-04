#include <iostream>
using namespace std;
long long gcd(long long x, long long y) {
	if (y == 0) {
		return x;
	}
	return gcd(y, x%y);
}
int main() {
	int T;
	long long a, b;
	cin >> T;
	while (T--) {
		cin >> a >> b;
		while (1) {
			if (a == 1) {
				cout << b << "\n";
				break;
			}
			
			long long x = (b % a == 0 ? b / a : b / a + 1);
			a = a * x - b;
			b = b * x;

			long long g = gcd(a, b);
			a /= g;
			b /= g;

		}
	}
}