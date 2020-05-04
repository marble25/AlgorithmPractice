#include <iostream>
using namespace std;
int main() {
	char x[101];
	cin >> x;
	for (int i = 0; ; i++) {
		if (x[i] == 0) {
			break;
		}
		cout << x[i];
		if ((i + 1) % 10 == 0) {
			cout << "\n";
		}
	}
}