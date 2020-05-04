#include <iostream>

using namespace std;

int main() {
	int n;
	int count1 = 0, count2 = 0;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int temp = i;
		while (temp % 2 == 0) {
			temp /= 2;
			count1++;
		}
		while (temp % 5 == 0) {
			temp /= 5;
			count2++;
		}
	}

	cout << (count1<count2?count1:count2) << "\n";

}