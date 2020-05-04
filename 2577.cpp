#include <iostream>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int re = a * b * c;
	int x[10] = { 0 };
	while (re > 0) {
		x[re % 10] ++;
		re /= 10;
	}
	for (int i = 0; i < 10; i++) {
		cout << x[i] << "\n";
	}
}