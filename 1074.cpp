#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n, r, c;
	cin >> n >> r >> c;
	int now = n;
	int count = 0;
	int x = 0, y = 0;
	now = pow(4, n - 1);
	n = pow(2, n);
	
	while (n > 0) {
		if (x == r && y == c) {
			break;
		}
		if (x + n / 2 > r && y + n / 2 > c) {

		}
		else if (x + n / 2 > r && y + n / 2 <= c) {
			y += n / 2;
			count += now;
		}
		else if (x + n / 2 <= r && y + n / 2 > c) {
			x += n / 2;
			count += now * 2;
		}
		else if (x + n / 2 <= r && y + n / 2 <= c) {
			x += n / 2;
			y += n / 2;
			count += now * 3;
		}
		n /= 2;
		now /= 4;
	}
	cout << count;
}