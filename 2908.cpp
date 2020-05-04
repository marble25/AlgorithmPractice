#include <iostream>
#include <cstring>
using namespace std;
int p(int x) {
	int result = 0;
	while (x > 0) {
		result = 10 * result + x % 10;
		x /= 10;
	}
	return result;
}
int main() {
	int a, b;
	cin >> a >> b;
	a = p(a);
	b = p(b);

	cout << (a > b ? a : b);
}