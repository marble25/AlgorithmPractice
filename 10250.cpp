#include <iostream>
using namespace std;
int main() {
	int T;
	int h, w, n;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> h >> w >> n;
		n--;
		cout << n % h + 1;
		cout.fill('0');
		cout.width(2);
		cout << n / h + 1 << "\n";
	}
}