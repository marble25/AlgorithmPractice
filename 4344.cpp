#include <iostream>
using namespace std;

int main() {
	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		int n;
		double avg = 0;
		double count = 0;
		int a[1000];
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> a[j];
			avg += a[j];
		}
		avg /= (double)n;
		for (int j = 0; j < n; j++) {
			if (avg < a[j]) {
				count += 1;
			}
		}
		cout << fixed;
		cout.precision(3);
		cout << count / (double)n * 100.0 << "%\n";

	}
}