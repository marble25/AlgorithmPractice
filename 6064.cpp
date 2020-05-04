#include <iostream>
using namespace std;
int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int m, n, x, y, j;
		cin >> m >> n >> x >> y;
		int result = -1;
		int mul = m * n;
		for(j=0;j<n;j++) {
			int year = j * m + x - 1;
			if (year % n + 1 == y) {
				result = year + 1;
				break;
			}
		}
		cout << result << "\n";
	}
}