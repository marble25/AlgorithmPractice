#include <iostream>
#include <cstring>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		char a[82];
		cin >> a;
		bool ch;
		int sum = 0;
		int count = 0;
		if (a[0] == 'O') {
			count = 1;
			sum = 1;
			ch = true;
		}
		else {
			ch = false;
		}
		for (int j = 1; j < strlen(a); j++) {
			if (a[j] == 'O') {
				if (ch) {
					count++;
					sum += count;
				}
				else {
					ch = true;
					count = 1;
					sum += count;
				}
			}
			else {
				ch = false;
				count = 0;
			}
		}
		cout << sum << "\n";
	}
}