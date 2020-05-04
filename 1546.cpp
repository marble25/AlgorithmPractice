#include <iostream>
using namespace std;

int main() {
	int n, max = -1;
	double x = 0;
	cin >> n;
	int a[10000];
	double b[10000];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > max) {
			max = a[i];
		}
	}

	for (int i = 0; i < n; i++) {
		b[i] = (double)a[i] / (double)max * 100.0;
		x += b[i];
	}
	cout.setf(ios::showpoint);
	cout << fixed;
	cout.precision(2);
	cout << (double)x / (double)n;
}