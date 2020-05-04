#include <iostream>
using namespace std;
int main() {
	int a, min = 9999;
	cin >> a;
	for (int i = 0; i * 5 <= a; i++) {
		if ((a - (i * 5)) % 3 == 0) {
			if ((a - (i * 5)) / 3 + i < min) {
				min = (a - (i * 5)) / 3 + i;
			}
		}
	}
	if (min == 9999) {
		cout << "-1\n";
	}
	else {
		cout << min << "\n";
	}
}