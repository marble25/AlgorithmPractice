#include <iostream>
using namespace std;
long long gcd(long long a, long long b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}
int main() {
	long long a, b;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		cout << a * b / gcd(a, b) << "\n";
	}
}