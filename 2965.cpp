#include <iostream>
using namespace std;

int dif(int x, int y) {
	int d = x - y;
	if (d < 0) {
		d = -d;
	}
	return d;
}
int main() {
	int a, b, c;
	cin >> a >> b >> c;

	int d[3];
	d[0] = dif(a, b);
	d[1] = dif(b, c);
	d[2] = dif(c, a);

	int temp;
	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 3; j++) {
			if (d[i] > d[j]) {
				temp = d[i];
				d[i] = d[j];
				d[j] = temp;
			}
		}
	}

	cout << d[1] - 1;
}