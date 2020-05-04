#include <iostream>
using namespace std;
bool check(int x) {
	int num = x % 10;
	x /= 10;
	int dif = num - x % 10;
	num = x % 10;
	x /= 10;
	while (x > 0) {
		if (num - x % 10 != dif) {
			return false;
		}
		num = x % 10;
		x /= 10;
	}
	return true;
}
int main() {
	int x;
	int count = 0;
	cin >> x;
	for (int i = 1; i <= x; i++) {
		if (i < 100) {
			count++;
			continue;
		}
		if (check(i)) {
			count++;
		}
	}
	cout << count;
}