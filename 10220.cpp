#include <iostream>
using namespace std;
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		if (n <= 3 || n == 6) {
			cout << "0\n";
		}
		else if (n == 4) {
			cout << "2\n";
		}
		else {
			cout << "1\n";
		}
	}
}