#include <iostream>
using namespace std;
int main() {
	int n, a, b;
	int result = 0;
	cin >> n >> a >> b;
	a--;
	b--;
	while (n > 0) {
		n /= 2;
		a /= 2;
		b /= 2;
		result++;
		if (a == b) {
			break;
		}
	}
	cout << result;
}
	
