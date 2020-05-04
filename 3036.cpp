#include <iostream>
using namespace std;
long long gcd(long long a, long long b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}
int main() {
	long long n;
	int a[105];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i < n; i++) {
		int g = gcd(a[0], a[i]);
		cout << a[0] / g << "/" << a[i] / g << "\n";
	}
}