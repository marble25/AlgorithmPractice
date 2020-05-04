#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	int x = sqrt(a);
	int y = sqrt(b);

	int min = 999999999;
	long long sum = 0;

	for (int i = x; i <= y; i++) {
		if (i*i >= a && i*i <= b) {
			if (min > i * i) {
				min = i * i;
			}
			sum += i * i;
		}
	}
	if (min == 999999999) {
		cout << -1;
		return 0;
	}
	cout << sum << "\n";
	cout << min;
}