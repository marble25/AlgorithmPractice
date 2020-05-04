#include <iostream>
using namespace std;
int cipher_sum(int x) {
	int sum = 0;
	while (x > 0) {
		sum += x % 10;
		x /= 10;
	}
	return sum;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= 1000000; i++) {
		if (i + cipher_sum(i) == n) {
			cout << i;
			return 0;
		}
	}
	cout << 0;
}