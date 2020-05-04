#include <iostream>
using namespace std;
int main() {
	int a[8];
	for (int i = 0; i < 8; i++) {
		cin >> a[i];
	}
	bool check = a[0]>a[1];
	for (int i = 2; i < 8; i++) {
		if (a[i - 1] > a[i] && !check) {
			cout << "mixed";
			return 0;
		}
		if (a[i - 1] < a[i] && check) {
			cout << "mixed";
			return 0;
		}
	}
	cout << (!check ? "ascending" : "descending");
}