#include <iostream>
using namespace std;

int main() {
	int c, temp, count = 0;
	cin >> c;
	temp = c;
	while (true) {
		int sum = temp / 10 + temp % 10;
		temp = (temp % 10) * 10 + sum % 10;
		count++;
		if (temp == c) {
			cout << count;
			break;
		}
	}
}