#include <iostream>
using namespace std;
int main() {
	int a[4];
	for (int i = 0; i < 3; i++) {
		int sum = 0;
		for (int j = 0; j < 4; j++) {
			cin >> a[j];
			sum += a[j];
		}
		char c;
		switch (sum) {
		case 0:
			c = 'D';
			break;
		case 1:
			c = 'C';
			break;
		case 2:
			c = 'B';
			break;
		case 3:
			c = 'A';
			break;
		case 4:
			c = 'E';
			break;
		}
		cout << c << "\n";
	}
}