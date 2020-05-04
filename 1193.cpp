#include <iostream>
using namespace std;
int main() {
	int a;
	int arr[20001];
	arr[0] = 0;
	for (int i = 1; i <= 20000; i++) {
		arr[i] = arr[i - 1] + i;
	}
	cin >> a;
	for (int i = 0; i <= 20000; i++) {
		if (arr[i] >= a) {
			int diff = arr[i] - arr[i - 1];
			int f = a - arr[i - 1];
			int s = diff - f + 1;
			if (i % 2 == 0) {
				cout << f << '/' << s;
			}
			else {
				cout << s << '/' << f;
			}
			
			break;
		}
	}
}